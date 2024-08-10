#include "common_procebar.h"

int main() {
    // 创建一个进度条
    int current_num = 0;
    int target_num = 100;
    procebar* pb = create_procebar(COMMON_PROCEBAR, &current_num, &target_num, true);

    // 更新进度条
    for (int i = 0; i < target_num; i++) {
        current_num++;
        update_procebar(pb);
        if (current_num % 10 == 0)
            printf("current_num: %d\n", current_num);
    }
}