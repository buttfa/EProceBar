#include "common_procebar.h"
#include <time.h>
int main() {
    // 定义任务进度参数
    int current = 0;
    int target = 100;
    int speed = 0;
    srand(time(NULL));
    char suffix[1024];
    // 定义通用进度条样式参数
    common_procebar_arg arg = {
        .prefix = (char*)"|",
        .suffix = suffix,
        .full_char = (char*)"█",
        .empty_char = (char*)"-"
    };
    // 使用COMMON_PROCEBAR样式创建进度条。
    procebar* pb = create_procebar(COMMON_PROCEBAR, &current, &target, (void*)&arg,true);
    
    // 模拟因任务进行造成的进度变化。
    while (current < target) {
        speed = rand() % 10;
        current += speed;
        if (current > target)
            current = target;
        sprintf(suffix, "| %dMB/%dMB %dMB/s", current, target, speed);
        update_procebar(pb);
        sleep(1);
    }
    

    // 释放进度条资源
    free_procebar((procebar**)&pb);
    return 0;
}