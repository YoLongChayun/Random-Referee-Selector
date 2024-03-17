#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int totalPeople, peopleToSelect, i, selected, scanResult;

    // 初始化随机数生成器
    srand((unsigned)time(NULL));

    while (1) {
        printf("请输入总人数 (或输入0结束程序): ");
        scanResult = scanf_s("%d", &totalPeople);

        // 检查输入是否为整数
        if (scanResult != 1) {
            printf("输入错误，请输入一个整数。\n");
            // 清除错误的输入
            while (getchar() != '\n');
            continue;
        }

        if (totalPeople == 0) {
            printf("程序已结束。\n");
            break; // 用户输入0，结束程序
        }

        printf("请输入需要抽取的人数 (或输入0结束程序): ");
        scanResult = scanf_s("%d", &peopleToSelect);

        // 检查输入是否为整数
        if (scanResult != 1) {
            printf("输入错误，请输入一个整数。\n");
            // 清除错误的输入
            while (getchar() != '\n');
            continue;
        }

        if (peopleToSelect == 0) {
            printf("程序已结束。\n");
            break; // 用户输入0，结束程序
        }

        if (peopleToSelect > totalPeople) {
            printf("抽取的人数不能超过总人数，请重新输入。\n");
            continue; // 返回循环开始，重新输入
        }

        printf("被选中的编号为: ");

        int* selections = malloc(totalPeople * sizeof(int)); // 动态分配数组
        if (selections == NULL) {
            printf("内存分配失败。\n");
            return 1; // 如果内存分配失败，则退出程序
        }
        for (i = 0; i < totalPeople; i++) {
            selections[i] = 0; // 初始化为未被选中
        }

        for (i = 0; i < peopleToSelect; i++) {
            do {
                selected = rand() % totalPeople; // 生成随机数选择人员
            } while (selections[selected] == 1); // 如果已被选中，则重新选择

            selections[selected] = 1; // 标记为已选中
            printf("%d ", selected + 1); // 输出被选中的人员编号，编号从1开始
        }

        printf("\n");
        free(selections); // 释放动态分配的内存
    }

    return 0;
}
