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
#### 通用进度条有着较高的可扩展性，允许在一定程度上自定义样式。可以通过以下方式创建一个通用进度条。
```c
#include "common_procebar.h"

int main() {
    // 创建进度条
    int current = 0;
    int target = 100;
    procebar* pb = create_procebar(COMMON_PROCEBAR, &current, &target, arg,true); // 使用COMMON_PROCEBAR样式
    return 0;
}
```


## EProceBar自定义样式