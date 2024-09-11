#ifndef __PROCEBAR_H__
#define __PROCEBAR_H__
/**
 * @file procebar.h
 * @author  buttfa (1662332017@qq.com)
 * @brief EProceBar的库头文件
 * @version 0.1
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <termios.h>
#include <unistd.h>


/**
 * @brief procebar_style结构体，用于定义进度条的样式
 * 
 */
typedef struct PROCEBAR_STYLE {
    int length;

    void (*print)(char* str, void* arg);

    void (*start)(void* arg);
    void (*end)(void* arg);

    char* (*get_prefix)(void* arg);
    char* (*get_suffix)(void* arg);
    
    char* (*get_full_char)(int index, void* arg); // 包含左边界字符
    char* (*get_empty_char)(int index, void* arg); // 包含右边界字符

    bool is_terminal;
} procebar_style;

/**
 * @brief procebar结构体，用于定义进度条
 * 
 */
typedef struct PROCEBAR {
    procebar_style style;  // 进度条样式
    
    void* arg;             // 进度条所需参数
    int* current_num;      // 当前进度
    int* target_num;       // 目标进度
    int x;
    int y;
} procebar;

/**
 * @brief 创建进度条
 * 
 * @param style 指定进度条样式
 * @param current_num 当前进度
 * @param target_num 目标进度
 * @return procebar* 返回值为创建的进度条指针
 */
procebar* create_procebar(procebar_style style, int* current_num, int* target_num, void* arg);

/**
 * @brief 更新进度条显示
 * 
 * @param pb 所需操作的进度条指针
 * @return int 指示进度条是否更新成功
 */
int update_procebar(procebar* pb);

/**
 * @brief 释放进度条内存，并将pb指针置为NULL
 * 
 * @param pb 所需操作的进度条指针
 * @return int 指示进度条是否释放成功
 */
int free_procebar(procebar** pb);

/**
 * @brief 清除进度条显示
 * 
 * @param pb 所需操作的进度条指针
 * @return int 指示进度条是否清除成功
 */
int clear_procebar(procebar* pb);
#endif