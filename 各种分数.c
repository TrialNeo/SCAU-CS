// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/6.
// 15 14 13 12 11 10 9 8 7 6 5

#include <stdio.h>


int main() {
    int score[4] = {4, 3, 2, 1};
    int can[11] = {0}; // 最大10分，开11个足够

    for (int mask = 0; mask < 16; mask++) {
        int total = 0;
        for (int i = 0; i < 4; i++) {
            if (mask & (1 << i)) {
                total += score[i];
            }
        }
        can[total] = 1;
    }

    int count = 0;

    for (int i = 0; i <= 10; i++) {
        if (can[i]) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n%d", count);
    return 0;
}
