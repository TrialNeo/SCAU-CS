// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/2.

// Description
// 由键盘输入20个整数，统计不同数字的个数。

// Description
//     由键盘输入20个整数，统计不同数字的个数。
// 输入样例
//     70  5  14  22  19  2  99  67  13  66  5  93  44  38  22  11  39  22  33  11
// 输出样例
//     16
// 提示
//     因为5有1个重复数字，11有1个重复数字，22有2个重复数字

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int main(int argc, char *argv[]) {
    //最简单直接的方法就是每次录入都去搜索一遍:n!
    // int temp = 0, count = 0,
    //         array[20] = {0};
    // for (int i = 0; i < 20; i++) {
    //     char flag = 1;
    //     scanf("%d", &temp);
    //     for (int j = 0; j < count; j++) {
    //         if (array[j] == temp) {
    //             flag = 0;
    //             break;
    //         }
    //     }
    //     if (flag) {
    //         array[count++] = temp;
    //     }
    // }

    //这个解法还是不太符合我的要求hh 可以试试排序去重
    int temp = 0, count = 1, array[20] = {0};
    for (int i = 0; i < 20; i++) {
        scanf("%d", array + i);
    }
    qsort(array, 20, sizeof(int), cmp);

    for (int i = 1; i < 20; i++) {
        if (array[i] != array[i - 1]) {
            count++;
        }
    }
    printf("%d", count);
}
