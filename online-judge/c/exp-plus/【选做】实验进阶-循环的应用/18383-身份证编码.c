// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/1/1.
#include <math.h>
#include  <stdio.h>
#include <string.h>

void c18383() {
    char identity[19] = {'\0'}; //最后一位是'\0'
    gets(identity);
    //440106 19780910 123
    if (strlen(identity) != 17) {
        puts("ERROR");
        return;
    }
    int S = 0;
    char C = 0;
    for (int i = 0; i < 17; i++) {
        S += (int) ((identity[i] - '0') * pow(2, 17 - i));
    }
    C = (char) ((12 - S % 11) % 11);
    if (C == 10) {
        identity[17] = 'X';
    } else {
        identity[17] = '0' + C;
    }

    puts(identity);
}
