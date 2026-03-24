// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/1.

#include <stdio.h>

int main() {
    float score, sum;
    for (int i = 0; i < 10; i++) {
        scanf("%f", &score);
        sum += score;
    }
    printf("%.2f", sum / 10);
}
