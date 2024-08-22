### <div align="center">|[简体中文](EProceBar_Style.md)|[English](../en/EProceBar_Style_en.md)|</div>

## <div align="center">目录</div>
- [EProceBar预设样式](#eprocebar预设样式)
  - [1. 传输进度条](#1-传输进度条)
  - [2. 任务进度条](#2-任务进度条)
  - [3. 通用进度条](#3-通用进度条)
- [EProceBar自定义样式](#eprocebar自定义样式)

## EProceBar预设样式
#### 1. 传输进度条
#### 2. 任务进度条
#### 3. 通用进度条
#### ①通用进度条有着较高的可扩展性，允许在一定程度上自定义样式。可以通过以下方式创建一个通用进度条。
```c
#include "common_procebar.h"

int main() {
    // 定义任务进度参数
    int current = 0;
    int target = 100;
    // 定义通用进度条样式参数
    common_procebar_arg arg = {
        .prefix = (char*)"|",
        .suffix = (char*)"|",
        .full_char = (char*)"█",
        .empty_char = (char*)"-"
    };
    // 使用COMMON_PROCEBAR样式创建进度条。
    // 注：如果使用通用进度条的默认样式，则无需传入arg，对应位置传入NULL即可。
    procebar* pb = create_procebar(COMMON_PROCEBAR, &current, &target, (void*)&arg,true);
    
    // 模拟因任务进行造成的进度变化。
    while (current < target) 
        update_procebar(pb);
    

    // 释放进度条资源
    free_procebar((procebar**)&pb);
    return 0;
}
```
#### ②通用进度条除了可以通过修改样式参数来修改进度条样式外，还可以通过不断变更前后缀内容来实现修改进度条格式。<br>以下，给出一个例子，为使用通用进度条间接实现传输进度条。


## EProceBar自定义样式
#### 1. 创建进度条参数结构体（非必要，只有在你的自定义样式中需要使用到某些参数时才需要定义）。
#### 此处给出color_procebar进度条参数结构体示例。
```c
/**
 * @brief 彩色进度条参数结构体
 * 
 */
typedef struct {
    int* current_num;
    int* target_num;
    int length;
} color_procebar_arg;
```
#### 2. 创建一个进度条样式宏定义。
#### 此处给出color_procebar样式结构体示例，由于篇幅限制，此处无法给出样式结构体中成员函数的具体实现，详情请参考[color_procebar.c](../../lib/procebar/procebar_style/color_procebar.c)。
```c
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
```
#### 如果想要自定义进度条样式，推荐参考color_procebar进度条示例(包含[源文件](../../lib/procebar/procebar_style/color_procebar.c)和[头文件](../../lib/procebar/procebar_style/color_procebar.h))，其实现了随时间变化的彩色进度条，对于深入了解如何自定义进度条样式具有很大帮助。