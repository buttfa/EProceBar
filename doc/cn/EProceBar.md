### <div align="center">|[简体中文](EProceBar.md)|[English](../en/EProceBar_en.md)|</div>

## <div align="center">目录</div> 
- [EProceBar库使用](#eprocebar库使用)
- [函数解析](#函数解析)

## EProceBar库使用
#### 1. EProceBar快速使用
```c
#include "procebar.h"

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
    procebar pb = create_procebar(COMMON_PROCEBAR, &current, &target, (void*)&arg);
    
    // 模拟因任务进行造成的进度变化。
    while (current < target) {
        current++;
        update_procebar(&pb);
    }
    
    return 0;
}
```

## 函数解析
|函数声明|函数作用|注意|
|:-|:-|:-|
|procebar create_procebar(procebar_style style, int* current_num, int* target_num, void* arg)|创建并返回进度条对象。|1.procebar_style可以使用[EProceBar预设样式](EProceBar_Style.md#eprocebar预设样式)，也可以[自定义样式](EProceBar_Style.md#eprocebar自定义样式)。|
|int update_procebar(procebar* pb)|更新pb进度条的显示。||
|int clear_procebar(procebar* pb)|清除pb进度条的显示。|1. 只适用于显示于终端的进度条。|