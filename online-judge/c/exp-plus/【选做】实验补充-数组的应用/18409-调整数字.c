// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/1.

// Description
//     给你N个整数构成的数列，要求将数列中的所有负数调整到数列前面，将正数调整到数列后面
// （保持负数之间先后顺序，且保持正数之间的先后顺序）
// 例如：原来是1，0，5，-2，0，-3，3.经过f处理后变成-2，-3，0，0，1，5，3
//
// 输入格式
//     第一行一个正整数N(N不大于20)
//      第二行是N个整数，每个整数由一个空格分隔
//
// 输出格式
//     处理后的数列，每个数之间由一个空格分隔
// 输入样例
//     7
// 1 0 5 -2 0 -3 3
//
// 输出样例
//     -2 -3 0 0 1 5 3

#include <stdio.h>

//这个想法是双队列，空间换时间,分为非负数，负数两个队列即可.
int main(int argc, char *argv[]) {
    int n = 0, temp = 0,
            arr_neg[20], count_neg = 0, count_zero = 0,
            arr_pos[20], count_pos = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp < 0) {
            arr_neg[count_neg++] = temp;
            continue;
        }
        if (temp == 0) {
            count_zero++;
            continue;
        }
        arr_pos[count_pos++] = temp;
    }

    for (int i = 0; i <count_neg; i++) {
        printf("%d ", arr_neg[i]);
    }
    for (int i = 0; i < count_zero; i++) {
        printf("0 ");
    }
    for (int i = 0; i < count_pos; i++) {
        printf("%d ", arr_pos[i]);
    }
}
