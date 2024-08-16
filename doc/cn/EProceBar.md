### <div align="center">|[简体中文](EProceBar.md)|[English](../en/EProceBar_en.md)|</div>

## <div align="center">目录</div> 
- [EProceBar库使用](#eprocebar库使用)
- [函数解析](#函数解析)

## EProceBar库使用
#### 1. EProceBar快速使用
```c
#include "procebar.h"

int main() {
    // 创建进度条
    int current = 0;
    int target = 100;
    procebar* pb = create_procebar(COMMON_PROCEBAR, &current, &target, true); // 使用COMMON_PROCEBAR样式
    if (pb == NULL) { 
        printf("Failed to create progress bar!\n");
        return -1;
    }

    // 模拟因任务进行造成的进度变化。
    while (current < target) {
        current++;
        update_procebar(pb);
    }

    // 释放内存。注：free_procebar函数不仅会释放pb指针指向的内存，还会将pb
    //              置为NULL，以防出现野指针。
    free_procebar((procebar**)&pb);
    return 0;
}
```

## 函数解析
|函数声明|函数作用|注意|
|:-|:-|:-|
|procebar* create_procebar(procebar_style style, int* current_num, int* target_num, bool is_terminal);|创建并返回进度条对象指针。|1.procebar_style可以使用[EProceBar预设样式]()，也可以[自定义样式]()。<br>2.is_terminal参数为true时，表示进度条在终端中显示，为false时，表示进度条在非终端中显示。|
|int update_procebar(procebar* pb);|更新pb进度条的显示。||
|int free_procebar(procebar** pb);|释放pb进度条的内存。|1. free_procebar函数不仅会释放pb指针指向的内存，还会将pb置为NULL，以防出现野指针。<br>2. 常用使用方式：free_procebar((procebar**)&pb);|
|int clear_procebar(procebar* pb);|清除pb进度条的显示。|1. 只适用于显示于终端的进度条。|