/**
 * @file common_procebar.c
 * @author  buttfa (1662332017@qq.com)
 * @brief 通用进度条样式的实现
 * @version 0.1
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "common_procebar.h"

/**
 * @brief 开始函数
 * 
 * @param arg 用于通用进度条的参数
 */
void common_procebar_start(void* arg) {    
}

/**
 * @brief 结束函数
 * 
 * @param arg 用于通用进度条的参数
 */
void common_procebar_end(void* arg) {
}

/**
 * @brief 获取前缀
 * 
 * @param arg 用于通用进度条的参数
 * @return char* 返回前缀
 */
char* common_procebar_prefix(void* arg) {
    // 如果arg为空，则使用COMMON_PROCEBAR_ARG中的前缀
    if (arg == NULL)
        return COMMON_PROCEBAR_ARG.prefix;
    else 
        return ((common_procebar_arg*)arg)->prefix;
}

/**
 * @brief 获取后缀
 * 
 * @param arg 用于通用进度条的参数
 * @return char* 返回后缀
 */
char* common_procebar_suffix(void* arg) {
    // 如果arg为空，则使用COMMON_PROCEBAR_ARG中的后缀
    if (arg == NULL)
        return COMMON_PROCEBAR_ARG.suffix;
    else 
        return ((common_procebar_arg*)arg)->suffix;
}

/**
 * @brief 获取空位字符
 * 
 * @param index 
 * @param arg 用于通用进度条的参数
 * @return char* 返回空位字符
 */
char* common_procebar_empty_char(int index, void* arg) {
    // 如果arg为空，则使用COMMON_PROCEBAR_ARG中的空位字符
    if (arg == NULL)
        return COMMON_PROCEBAR_ARG.empty_char;
    else 
        return ((common_procebar_arg*)arg)->empty_char;
}

/**
 * @brief 获取满位字符
 * 
 * @param index 
 * @param arg 用于通用进度条的参数
 * @return char* 返回满位字符
 */
char* common_procebar_full_char(int index, void* arg) {
    // 如果arg为空，则使用COMMON_PROCEBAR_ARG中的满位字符
    if (arg == NULL)
        return COMMON_PROCEBAR_ARG.full_char;
    else 
        return ((common_procebar_arg*)arg)->full_char;
}

/**
 * @brief 打印字符串
 * 
 * @param str 需要打印的字符串
 * @param arg 用于通用进度条的参数
 */
void common_procebar_print(char* str, void* arg) {
    printf("%s", str);
    fflush(stdout);
}