#include "common_procebar.h"
  
int main() {
    // 创建一个进度条
    int current_num = 0;
    int target_num = 100;
    procebar* pb = create_procebar(COMMON_PROCEBAR, &current_num, &target_num, true);
    procebar* pb_c = create_procebar(COMMON_PROCEBAR, &current_num, &target_num, true);
    common_procebar_arg arg = {
        .prefix = (char*)"|",
        .suffix = (char*)"|",
        .full_char = (char*)"█",
        .empty_char = (char*)"-"
    };
    pb->arg = (void*)&arg;

    // 更新进度条
    for (int i = 0; i < target_num; i++) {
        current_num++;
        update_procebar(pb);
        update_procebar(pb_c);
        if (current_num % 10 == 0)
            printf("current_num: %d\n", current_num);
    }

    clear_procebar(pb);
    free_procebar((procebar**)&pb);
    free_procebar((procebar**)&pb_c);
    printf("Common Procebar Test Passed!\n");
    return 0;
}