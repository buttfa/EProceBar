/**
 * @file procebar.c
 * @author  buttfa (1662332017@qq.com)
 * @brief EProceBar库的实现文件
 * @version 0.1
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "procebar.h"

/**
 * @brief 最大可能的 ESC 序列长度
 * 
 */
#define ESC_SEQ_LEN 10

/**
 * @brief 发送 ESC 序列来获取光标位置
 * 
 * @param fd 文件描述符
 */
static void send_cursor_position_request(int fd) {
    write(fd, "\033[6n", 4); // 发送 ESC 序列
}

/**
 * @brief 解析 ESC 序列以获取光标位置
 * 
 * @param buf 需要解析的 ESC 序列
 * @param row 获取的行号存放的指针
 * @param col 获取的列号存放的指针
 * @return int 返回1表示解析成功，0表示解析失败
 */
static int parse_cursor_position(const char *buf, int *row, int *col) {
    const char *p = buf;
    if (strncmp(p, "\033[", 2) != 0) return 0; // 不是以 ESC 序列开始
    p += 2;

    int num = 0;
    while (*p && *p >= '0' && *p <= '9') {
        num = num * 10 + (*p - '0');
        p++;
    }

    *row = num;
    if (*p != ';') return 0; // 没有分号分隔
    p++;

    num = 0;
    while (*p && *p >= '0' && *p <= '9') {
        num = num * 10 + (*p - '0');
        p++;
    }

    *col = num;
    return 1;
}

/**
 * @brief 获取当前光标位置
 * 
 * @param row 获取的行号存放的指针
 * @param col 获取的列号存放的指针
 * @return true 获取成功
 * @return false 获取失败
 */
static bool get_cursor_position(int *row, int *col) {
    int fd = fileno(stdin);
    struct termios oldt, newt;

    // 获取当前终端属性
    tcgetattr(fd, &oldt);
    memcpy(&newt, &oldt, sizeof(newt));

    // 设置为原始模式
    cfmakeraw(&newt);
    tcsetattr(fd, TCSANOW, &newt);

    // 发送 ESC 序列以获取光标位置
    send_cursor_position_request(fd);

    // 读取响应
    char buf[ESC_SEQ_LEN];
    read(fd, buf, ESC_SEQ_LEN);

    if (!parse_cursor_position(buf, row, col))
        return false;

    // 恢复终端设置
    tcsetattr(fd, TCSANOW, &oldt);
    return true;
}

/**
 * @brief 创建进度条
 * 
 * @param style 指定进度条样式
 * @param current_num 当前进度
 * @param target_num 目标进度
 * @return procebar* 返回值为创建的进度条指针
 */
procebar* create_procebar(procebar_style style, int* current_num, int* target_num, bool is_terminal) {
    // 申请内存
    procebar* pb = (procebar*)malloc(sizeof(procebar));
    memset(pb, 0, sizeof(procebar));

    // 初始化进度条
    pb->is_terminal = is_terminal;
    // pb->is_save = true;
    pb->style = style;
    pb->arg = NULL;
    pb->current_num = current_num;
    pb->target_num = target_num;
    pb->x = 0;
    pb->y = 0;

    // 返回进度条指针
    return pb;
}

/**
 * @brief 释放进度条内存，并将pb指针置为NULL
 * 
 * @param pb 所需操作的进度条指针
 * @return int 指示进度条是否释放成功
 */
int free_procebar(procebar** pb) {
    // 进度条指针为空则返回0
    if (*pb == NULL) 
        return 0;

    free(*pb);
    *pb = NULL;
    // 释放进度条内存并返回1
    return 1;
}

/**
 * @brief 处理并输出进度条
 * 
 * @param pb 
 */
static void handle_procebar(procebar* pb) {
    // 判断进度条指针是否为空
    if (pb == NULL)
        return;

    // 计算进度
    int percent = *pb->current_num * pb->style.length / *pb->target_num;

    char procebar_str[1024] = "";
    // 输出前缀
    strcat(procebar_str, pb->style.get_prefix(pb->arg));
    // 输出进度条
    for (int i = 0; i < pb->style.length; i++) {
        if (i < percent) 
            strcat(procebar_str, pb->style.get_full_char(i, pb->arg));
        else
            strcat(procebar_str, pb->style.get_empty_char(i, pb->arg));
    }
    // 输出后缀
    strcat(procebar_str, pb->style.get_suffix(pb->arg));

    // 输出进度条
    pb->style.print(procebar_str, pb->arg);
}

/**
 * @brief 更新进度条显示
 * 
 * @param pb 所需操作的进度条指针
 * @return int 指示进度条是否更新成功
 */
int update_procebar(procebar* pb) {
    // 判断进度条指针是否为空
    if (pb == NULL)
        return 0;

    // 判断是否为终端模式且坐标为(0, 0)
    if (pb->is_terminal && pb->x == 0 && pb->y == 0) {
        // 如果是，则获取当前光标坐标为进度条坐标
        get_cursor_position(&pb->y, &pb->x);
        // 输出一个"\n"，使光标向下移动一行，以免其它输出覆盖进度条
        printf("\n");
    }

    // 判断是否为终端模式，如果是，则保存当前光标位置，
    // 并将光标移动到进度条坐标
    int row, col;
    if (pb->is_terminal) {
        // 保存当前光标位置
        get_cursor_position(&row, &col);

        // 将光标移动到进度条坐标，清除掉当前行，并隐藏光标
        //      移动        清除   隐藏
        printf("\033[%d;%dH\033[K\x1B[?25l", pb->y, pb->x);
        fflush(stdout);
    }

    // 处理并进度条
    handle_procebar(pb);

    // 如果是终端模式，则将光标移动回保存的位置
    // 并显示光标
    if (pb->is_terminal) {
        //      移动        显示
        printf("\033[%d;%dH\033[?25h", row, col);
        fflush(stdout);
    }


    return 1;
}