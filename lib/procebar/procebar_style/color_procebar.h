#ifndef __COLOR_PROCEBAR_H__
#define __COLOR_PROCEBAR_H__
/**
 * @file color_procebar.h
 * @author  buttfa (1662332017@qq.com)
 * @brief 自定义彩色进度条样式的示例头文件
 * @version 0.1
 * @date 2024-08-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "procebar.h"
#include <stdio.h>
#include <time.h>

/**
 * @brief 彩色进度条参数结构体
 * 
 */
typedef struct {
    int* current_num;
    int* target_num;
    int length;
} color_procebar_arg;

/**
 * @brief ANSI颜色定义
 * 
 */
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_ORANGE  "\x1b[38;5;208m"  // 256色橙色
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_PURPLE  "\x1b[35m"
#define ANSI_COLOR_RESET   "\x1b[0m"
static char* ANSI_COLOR[] = {
    ANSI_COLOR_RED,
    ANSI_COLOR_ORANGE,
    ANSI_COLOR_YELLOW,
    ANSI_COLOR_GREEN,
    ANSI_COLOR_CYAN,
    ANSI_COLOR_BLUE,
    ANSI_COLOR_PURPLE
};

/**
 * @brief 彩色进度条默认长度 
 * 
 */
#define COLOR_PROCEBAR_LENGTH 20

/**
 * @brief 彩色进度条样式宏定义
 * 
 */
#define COLOR_PROCEBAR (procebar_style){\
    .length = COLOR_PROCEBAR_LENGTH, \
    .print = color_procebar_print, \
    .start = color_procebar_start, \
    .end = color_procebar_end, \
    .get_prefix = color_procebar_prefix, \
    .get_suffix = color_procebar_suffix, \
    .get_full_char = color_procebar_full_char, \
    .get_empty_char = color_procebar_empty_char, \
}

/**
 * @brief 开始函数
 * 
 * @param arg 用于彩色进度条的参数
 */
void color_procebar_start(void* arg);

/**
 * @brief 结束函数
 * 
 * @param arg 用于彩色进度条的参数
 */
void color_procebar_end(void* arg);

/**
 * @brief 获取前缀
 * 
 * @param arg 用于彩色进度条的参数
 * @return char* 返回前缀
 */
char* color_procebar_prefix(void* arg);

/**
 * @brief 获取后缀
 * 
 * @param arg 用于彩色进度条的参数
 * @return char* 返回后缀
 */
char* color_procebar_suffix(void* arg);

/**
 * @brief 获取空位字符
 * 
 * @param index 
 * @param arg 用于彩色进度条的参数
 * @return char* 返回空位字符
 */
char* color_procebar_empty_char(int index, void* arg);

/**
 * @brief 获取满位字符
 * 
 * @param index 
 * @param arg 用于彩色进度条的参数
 * @return char* 返回满位字符
 */
char* color_procebar_full_char(int index, void* arg);

/**
 * @brief 打印字符串
 * 
 * @param str 需要打印的字符串
 * @param arg 用于彩色进度条的参数
 */
void color_procebar_print(char* str, void* arg);

#endif