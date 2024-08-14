#include "color_procebar.h"

int main() {
    // 创建一个进度条
    int current_num = 0;
    int target_num = 100;
    color_procebar_arg arg = {
        .current_num = &current_num,
        .target_num = &target_num,
        .length = COLOR_PROCEBAR_LENGTH,
    };
    procebar* pb = create_procebar(COLOR_PROCEBAR, &current_num, &target_num, (void*)&arg);
    pb->arg = &arg;

    // 更新进度条
    while (current_num < target_num) {
        current_num++;
        update_procebar(pb);
    }

    free_procebar((procebar**)&pb);
    printf("Color procebar test finish!\n");
}