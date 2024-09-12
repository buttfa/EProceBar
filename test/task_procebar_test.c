#include "task_procebar.h"

int main() {
    // 定义任务进度参数
    int current_num = 0;
    int target_num = 4;
    char* tasks_name[5] = {(char*)"task1", (char*)"task2", (char*)"task3", (char*)"task4", (char*)"task5"};
    // 定义通用进度条样式参数
    task_procebar_arg arg = {
        .current_num = &current_num,
        .target_num = &target_num,
        .tasks_name = tasks_name,
    };
    // 创建进度条
    procebar pb = create_procebar(TASK_PROCEBAR, &current_num, &target_num, &arg);
    // 模拟因任务进行造成的进度变化。
    while (current_num < target_num) {
        current_num++;
        // 更新进度条
        update_procebar(&pb);
        // 模拟任务执行时间
        sleep(1);
    }
}