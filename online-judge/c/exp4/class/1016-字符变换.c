// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/1.
#include <stdio.h>
int main() {
    char str[6];
    gets(str);
    for (int i = 0; i < 5; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    puts(str);
}