// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/16.

// Description
// 由键盘输入10个数，用“冒泡法”对10个数从小到大排序，并按格式要求输出。代码如下，请填充完整。

#include "stdio.h"

int main() {
    int a[10], i, j, t;
    for (i = 0; i < 10; i++)
        scanf("%d", a + i);
    for (int i = 0; i < 10; i++) {
        for (j = 0; j < 9 - i; j++)
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
    }
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
}
