// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/1.

#include <stdio.h>
#include <math.h>

int main() {
    unsigned int n = 0,ans = 0;
    scanf("%u", &n);
    ans = n;
    for (unsigned i = 1;i<n;i++) {
        ans *= i;
    }
    printf("%d", ans);
}
