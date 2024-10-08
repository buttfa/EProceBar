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
#define ESC_SEQ_LEN 20

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
    write(fd, "\033[6n", 4);

    // 读取响应
    char buf[ESC_SEQ_LEN];
    read(fd, buf, ESC_SEQ_LEN);

    // 解析响应
    sscanf(buf, "\033[%d;%dR", row, col);

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
procebar create_procebar(procebar_style style, int* current_num, int* target_num, void* arg) {
    // 申请内存
    procebar pb;
    memset(&pb, 0, sizeof(procebar));

    // 初始化进度条
    pb.style = style;
    pb.arg = arg;
    pb.current_num = current_num;
    pb.target_num = target_num;
    pb.x = 0;
    pb.y = 0;

    // 返回进度条指针
    return pb;
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

    // 调用进度条开始函数
    pb->style.start(pb->arg);

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

    // 调用进度条结束函数
    pb->style.end(pb->arg);
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
    if (pb->style.is_terminal && pb->x == 0 && pb->y == 0) {
        // 如果是，则获取当前光标坐标为进度条坐标
        get_cursor_position(&pb->y, &pb->x);
        // 输出一个"\n"，使光标向下移动一行，以免其它输出覆盖进度条
        printf("\n");
    }

    // 判断是否为终端模式，如果是，则保存当前光标位置，
    // 并将光标移动到进度条坐标
    int row, col;
    if (pb->style.is_terminal) {
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
    if (pb->style.is_terminal) {
        //      移动        显示     重置文本样式
        printf("\033[%d;%dH\033[?25h\x1b[0m", row, col);
        fflush(stdout);
    }


    return 1;
}

/**
 * @brief 清除进度条显示
 * 
 * @param pb 所需操作的进度条指针
 * @return int 指示进度条是否清除成功
 */
int clear_procebar(procebar* pb) {
    // 判断进度条指针是否为空且是否为终端模式
    if (pb == NULL || !pb->style.is_terminal)
        return 0;

    // 保存当前光标位置
    int row = 0, col = 0;
    get_cursor_position(&row, &col);

    // 将光标移动到进度条坐标，清除掉当前行，并隐藏光标
    //      移动        清除   隐藏
    printf("\033[%d;%dH\033[K\x1B[?25l", pb->y, pb->x);
    fflush(stdout);

    // 将光标移动回保存的位置
    //      移动        显示     重置文本样式
    printf("\033[%d;%dH\033[?25h\x1b[0m", row, col);
    fflush(stdout);
    return 1;
}