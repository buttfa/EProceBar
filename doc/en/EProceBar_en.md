### <div align="center">|[简体中文](../cn/EProceBar.md)|[English](EProceBar_en.md)|</div>

## <div align="center">Directory</div>
- [EProceBar library usage](#eprocebar-library-usage)
- [Function Analysis](#function-analysis)

## EProceBar library usage
#### 1.  EProceBar Quick Use
```c
#include "procebar.h"

int main() {
    //Create progress bar
    int current = 0;
    int target = 100;
    procebar* pb=creat_procebar (COMMON_PROCEBAR,&current,&target, NULL, true);//Use COMMON-PROCEBAR style
    if (pb == NULL) { 
        printf("Failed to create progress bar!\n");
        return -1;
    }

    //Simulate the schedule changes caused by the progress of tasks.
    while (current < target) {
        current++;
        update_procebar(pb);
    }

    //Release memory. Note: The free_decebar function not only releases the memory pointed to by the PB pointer, but also
    //Set to NULL to prevent the occurrence of wild pointers.
    free_procebar((procebar**)&pb);
    return 0;
}
```

## Function analysis
|Function Declaration | Function Function Function | Attention|
|:-|:-|:-|
|procebar create_procebar (procebar_style style, int * current_num, int * target_num, void* arg); | Create and return a progress bar object| 1. Procebar_style can use [EPRoceBar preset style](EProceBar_Style_en.md#eprocebar-preset-style) or [Custom style](EProceBar_Style_en.md#eprocebar-custom-style).|
|int update_procebar(procebar* pb);| Update the display of the PB progress bar||
|int clear_procebar(procebar* pb);| Clear the display of the PB progress bar| 1. Only applicable to the progress bar displayed on the terminal|