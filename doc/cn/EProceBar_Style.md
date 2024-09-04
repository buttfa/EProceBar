### <div align="center">|[简体中文](EProceBar_Style.md)|[English](../en/EProceBar_Style_en.md)|</div>

## <div align="center">目录</div>
- [EProceBar预设样式](#eprocebar预设样式)
  - [1. 传输进度条](#1-传输进度条)
  - [2. 任务进度条](#2-任务进度条)
  - [3. 通用进度条](#3-通用进度条)
- [EProceBar自定义样式](#eprocebar自定义样式)

## EProceBar预设样式
#### 1. 传输进度条
#### [传输进度条使用示例](../../test/transmit_procebar_test.c)
#### 2. 任务进度条
#### [任务进度条使用示例](../../test/task_procebar_test.c)
#### 3. 通用进度条
#### ①通用进度条有着较高的可扩展性，允许在一定程度上自定义样式。此处给出一个[示例](../../test/common_procebar_test.c)。
#### ②通用进度条除了可以通过修改样式参数来修改进度条样式外，还可以通过不断变更前后缀内容来实现修改进度条格式。<br>以下，给出一个[示例](../../test/common_transmit_test.c)，为使用通用进度条间接实现传输进度条。


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
#### 此处给出color_procebar样式结构体示例，由于篇幅限制，此处无法给出样式结构体中成员函数的具体实现，详情请参考[color_procebar.c](../../eprocebar/procebar_style/color_procebar.c)。
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
#### 如果想要自定义进度条样式，推荐参考color_procebar进度条示例(包含[源文件](../../eprocebar/procebar_style/color_procebar.c)和[头文件](../../eprocebar/procebar_style/color_procebar.h))，其实现了随时间变化的彩色进度条，对于深入了解如何自定义进度条样式具有很大帮助。