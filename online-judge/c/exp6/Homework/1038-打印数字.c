// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/5.

#include  <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - i; j++) {
            putchar(' ');
        }
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }
        putchar('\n');
    }
    for (int i = n; i >= 1; i--) {
        for (int j = n - i; j >= 0; j--) {
            putchar(' ');
        }
        for (int j = 1; j <= i - 1; j++) {
            printf("%d", j);
        }
        for (int j = i - 2; j > 0; j--) {
            printf("%d", j);
        }
        putchar('\n');
    }
}
