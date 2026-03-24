// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/1.

#include <stdio.h>
#include <math.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    int root = (int) round(sqrt(n)); //round避免bug
    printf(root * root == n ? "Y" : "N");
    return 0;
}
