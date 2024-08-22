/**
 * @file transmit_procebar.c
 * @author  buttfa (1662332017@qq.com)
 * @brief 传输进度条样式的实现
 * @version 0.1
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "transmit_procebar.h"

/**
 * @brief 开始函数
 * 
 * @param arg 用于传输进度条的参数
 */
void transmit_procebar_start(void* arg) {
}

/**
 * @brief 结束函数
 * 
 * @param arg 用于传输进度条的参数
 */
void transmit_procebar_end(void* arg) {
}

/**
 * @brief 获取前缀
 * 
 * @param arg 用于传输进度条的参数
 * @return char* 返回前缀
 */
char* transmit_procebar_prefix(void* arg) {
    return "[";
}

/**
 * @brief 获取后缀
 * 
 * @param arg 用于传输进度条的参数
 * @return char* 返回后缀
 */
char* transmit_procebar_suffix(void* arg) {
    static char suffix[1024];
    sprintf(suffix, "] %.1f%s/%.1f%s %.1f%s/s", 
        HANDLE_SIZE(*((transmit_procebar_arg*)arg)->current_num),
        GET_UNIT(*((transmit_procebar_arg*)arg)->current_num),
        HANDLE_SIZE(*((transmit_procebar_arg*)arg)->target_num),
        GET_UNIT(*((transmit_procebar_arg*)arg)->target_num),
        HANDLE_SIZE(*((transmit_procebar_arg*)arg)->speed),
        GET_UNIT(*((transmit_procebar_arg*)arg)->speed));
    return suffix;
}

/**
 * @brief 获取空位字符
 * 
 * @param index 
 * @param arg 用于传输进度条的参数
 * @return char* 返回空位字符
 */
char* transmit_procebar_empty_char(int index, void* arg) {
    return " ";
}

/**
 * @brief 获取满位字符
 * 
 * @param index 
 * @param arg 用于传输进度条的参数
 * @return char* 返回满位字符
 */
char* transmit_procebar_full_char(int index, void* arg) {
    return "=";
}

/**
 * @brief 打印字符串
 * 
 * @param str 需要打印的字符串
 * @param arg 用于传输进度条的参数
 */
void transmit_procebar_print(char* str, void* arg) {
    printf("%s", str);
    fflush(stdout);
}