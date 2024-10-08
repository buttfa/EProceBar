#include "procebar.h"
#include <time.h>

int main() {
    // 定义任务进度参数
    int current_num = 0;
    int target_num = 1024*1024*76;
    int speed = 0;
    srand(time(NULL));
    // 定义传输进度条样式参数
    transmit_procebar_arg arg = {
        .prefix = (char*)"|",         // 非必要
        .suffix = (char*)"|",         // 非必要
        .full_char = (char*)"#",      // 非必要
        .empty_char = (char*)"-",     // 非必要
        .current_num = &current_num,  // 必要
        .target_num = &target_num,    // 必要
        .speed = &speed,              // 必要
    };
    // 创建进度条
    procebar pb = create_procebar(TRANSMIT_PROCEBAR, &current_num, &target_num, &arg);

    // 模拟因任务进行造成的进度变化。
    while (current_num < target_num) {
        speed = rand() % 1024*1024*10;
        current_num += speed;
        if (current_num > target_num)
            current_num = target_num;
        update_procebar(&pb);
        sleep(1);
    }
}