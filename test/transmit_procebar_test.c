#include "transmit_procebar.h"
#include <time.h>

int main() {
    // 定义任务进度参数
    int current_num = 0;
    int target_num = 1024*1024*76;
    int speed = 0;
    srand(time(NULL));
    // 定义传输进度条样式参数
    transmit_procebar_arg arg = {
        .current_num = &current_num,
        .target_num = &target_num,
        .speed = &speed,
    };
    // 创建进度条
    procebar* pb = create_procebar(TRANSMIT_PROCEBAR, &current_num, &target_num, &arg, true);

    // 模拟因任务进行造成的进度变化。
    while (current_num < target_num) {
        speed = rand() % 1024*1024*10;
        current_num += speed;
        if (current_num > target_num)
            current_num = target_num;
        update_procebar(pb);
        sleep(1);
    }

    // 释放进度条
    free_procebar((procebar**)&pb);
}