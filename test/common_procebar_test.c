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