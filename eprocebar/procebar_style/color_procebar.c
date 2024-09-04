/**
 * @file color_procebar.c
 * @author  buttfa (1662332017@qq.com)
 * @brief 自定义彩色进度条样式的示例源文件
 * @version 0.1
 * @date 2024-08-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "color_procebar.h"

/**
 * @brief 开始函数
 * 
 * @param arg 用于彩色进度条的参数
 */
void color_procebar_start(void* arg) {
}

/**
 * @brief 结束函数
 * 
 * @param arg 用于彩色进度条的参数
 */
void color_procebar_end(void* arg) {
}

/**
 * @brief 获取前缀
 * 
 * @param arg 用于彩色进度条的参数
 * @return char* 返回前缀
 */
char* color_procebar_prefix(void* arg) {
    static char prefix[128];
    strcpy(prefix, ANSI_COLOR[(time(NULL)+0)%7]);
    strcat(prefix, (char*)"[");
    return prefix;
}

/**
 * @brief 获取后缀
 * 
 * @param arg 用于彩色进度条的参数
 * @return char* 返回后缀
 */
char* color_procebar_suffix(void* arg) {
    static char suffix[28];
    strcpy(suffix, ANSI_COLOR[(time(NULL)+0)%7]);
    strcat(suffix, (char*)"]");
    return suffix;
}

/**
 * @brief 获取空位字符
 * 
 * @param index 
 * @param arg 用于彩色进度条的参数
 * @return char* 返回空位字符
 */
char* color_procebar_empty_char(int index, void* arg) {
    return (char*)" ";
}

/**
 * @brief 获取满位字符
 * 
 * @param index 
 * @param arg 用于彩色进度条的参数
 * @return char* 返回满位字符
 */
char* color_procebar_full_char(int index, void* arg) {
    static char full[128];
    // 获取颜色
    strcpy(full, ANSI_COLOR[(time(NULL)+index)%7]);

    // 判断是否是进度的最后一个字符
    static char* symbols[] = {(char*)"\\", (char*)"|", (char*)"/", (char*)"~" };
    static int times = 0;
    if (index == *((color_procebar_arg*)arg)->current_num * ((color_procebar_arg*)arg)->length / *((color_procebar_arg*)arg)->target_num - 1) 
        // 如果是进度最后一个字符，则返回依据时间依次返回symbols中的符号
        strcat(full ,symbols[(time(NULL)+(times = times < 4 ? times+1 : 0)*3) % 4]);
    else 
        // 否则返回"-"
        strcat(full, (char*)"-");

    return full;
}

/**
 * @brief 打印字符串
 * 
 * @param str 需要打印的字符串
 * @param arg 用于彩色进度条的参数
 */
void color_procebar_print(char* str, void* arg) {
    // 打印字符串
    printf("%s", str);
    fflush(stdout);
}