// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/6.
// 15 14 13 12 11 10 9 8 7 6 5

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    int score[10] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6};
    int can[151] = {1, 0};
    int total = 0;
    for (int mask = 0; mask < 1024; mask++) {
        total = 0;
        for (int i = 0; i < 10; ++i) {
            if (mask & 1 << i) {
                total += score[i];
            }
            can[total] = 1;
        }
    }
    // 这个是取子集，有空写写笔记

    int count = 0;

    for (int i = 0; i <= 150; i++) {
        if (can[i]) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n%d", count);
    return 0;
}
