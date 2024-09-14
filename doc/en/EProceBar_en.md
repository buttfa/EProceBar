### <div align="center">|[简体中文](../cn/EProceBar.md)|[English](EProceBar_en.md)|</div>

## <div align="center">Directory</div>
- [EProceBar library usage](#eprocebar-library-usage)
- [Function Analysis](#function-analysis)

## EProceBar library usage
#### 1.  EProceBar Quick Use
```c
#include "procebar.h"

int main() {
    // Define task parameters
    int current = 0;
    int target = 100;
    // Define common progress bar style parameters
    common_procebar_arg arg = {
        .prefix = (char*)"|",
        .suffix = (char*)"|",
        .full_char = (char*)"█",
        .empty_char = (char*)"-"
    };
    // Create a progress bar using the COMMON_PROCEBAR style.
    // Note: If using the default style of the common progress bar, there is no need to pass arg, just pass NULL at the corresponding position.
    procebar pb = create_procebar(COMMON_PROCEBAR, &current, &target, (void*)&arg);
    
    // Simulate the schedule changes caused by the progress of tasks.
    while (current < target) {
        current++;
        update_procebar(&pb);
    }
    
    return 0;
}
```

## Function analysis
|Function Declaration|Function Function Function|Note|
|:-|:-|:-|
|procebar create_procebar(procebar_style style, int* current_num, int* target_num, void* arg) | Create and return a progress bar object| 1. Procebar_style can use [EPRoceBar preset style](EProceBar_Style_en.md#eprocebar-preset-style) or [Custom style](EProceBar_Style_en.md#eprocebar-custom-style).|
|int update_procebar(procebar* pb)| Update the display of the progress bar||
|int clear_procebar(procebar* pb)| Clear the display of the progress bar| 1. Only applicable to the progress bar displayed on the terminal|