// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/6.

#include <stdio.h>

void input(int a[]) {
    for (int i = 0; i < 10; i++) {
        scanf("%d", a + i);
    }
}

void swap(int a[]) {
    int minIndex = 0, maxIndex = 0;
    for (int i = 0; i < 10; i++) {
        if (a[minIndex] > a[i]) {
            minIndex = i;
        }
    }
    int temp = a[0];
    a[0] = a[minIndex];
    a[minIndex] = temp;
    for (int i = 0; i < 10; i++) {
        if (a[maxIndex] < a[i]) {
            maxIndex = i;
        }
    }
    temp = a[9];
    a[9] = a[maxIndex];
    a[maxIndex] = temp;
}

void display(int a[]) {
    int i;
    for (i = 0; i < 10; i++)
        printf("%d\n", a[i]);
}

int main() {
    int a[10];
    input(a);
    printf("input done\n");
    swap(a);
    printf("swap done\n");
    display(a);
    printf("display done\n");
    return 0;
}
