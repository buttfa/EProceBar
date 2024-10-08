#ifndef __COMMON_PROCEBAR_H__
#define __COMMON_PROCEBAR_H__
/**
 * @file common_procebar.h
 * @author  buttfa (1662332017@qq.com)
 * @brief 定义了通用进度条样式
 * @version 0.1
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "procebar.h"

/**
 * @brief 通用进度条参数结构体
 * 
 */
typedef struct {
    char* prefix;
    char* suffix;
    char* full_char;
    char* empty_char;
} common_procebar_arg;

/**
 * @brief 通用进度条默认长度
 * 
 */
#define COMMON_PROCEBAR_LENGTH 20

/**
 * @brief 通用进度条样式宏定义
 * 
 */
#define COMMON_PROCEBAR (procebar_style){\
    .length = COMMON_PROCEBAR_LENGTH, \
    .print = common_procebar_print, \
    .start = common_procebar_start, \
    .end = common_procebar_end, \
    .get_prefix = common_procebar_prefix, \
    .get_suffix = common_procebar_suffix, \
    .get_full_char = common_procebar_full_char, \
    .get_empty_char = common_procebar_empty_char, \
    .is_terminal = true, \
}

/**
 * @brief 通用进度条默认参数，在传入的参数无效时使用此参数
 * 
 */
#define COMMON_PROCEBAR_ARG (common_procebar_arg){\
    .prefix = (char*)"[", \
    .suffix = (char*)"]", \
    .full_char = (char*)"=", \
    .empty_char = (char*)" ", \
}

/**
 * @brief 开始函数
 * 
 * @param arg 用于通用进度条的参数
 */
void common_procebar_start(void* arg);

/**
 * @brief 结束函数
 * 
 * @param arg 用于通用进度条的参数
 */
void common_procebar_end(void* arg);

/**
 * @brief 获取前缀
 * 
 * @param arg 用于通用进度条的参数
 * @return char* 返回前缀
 */
char* common_procebar_prefix(void* arg);

/**
 * @brief 获取后缀
 * 
 * @param arg 用于通用进度条的参数
 * @return char* 返回后缀
 */
char* common_procebar_suffix(void* arg);

/**
 * @brief 获取空位字符
 * 
 * @param index 
 * @param arg 用于通用进度条的参数
 * @return char* 返回空位字符
 */
char* common_procebar_empty_char(int index, void* arg);

/**
 * @brief 获取满位字符
 * 
 * @param index 
 * @param arg 用于通用进度条的参数
 * @return char* 返回满位字符
 */
char* common_procebar_full_char(int index, void* arg);

/**
 * @brief 打印字符串
 * 
 * @param str 需要打印的字符串
 * @param arg 用于通用进度条的参数
 */
void common_procebar_print(char* str, void* arg);

#endif