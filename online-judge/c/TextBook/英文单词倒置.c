// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/6.

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char str[255] = {0}, stack[255] = {0}, buffer[255] = {0};
    int stack_offset = 0, buffer_offset = 0;
    gets(str);
    int len = strlen(str);
    for (int i = 0; i <= len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' ) {
            stack[stack_offset++] = str[i];
            continue;
        }
        for (int j = stack_offset - 1; j >= 0; j--) {
            buffer[buffer_offset++] = stack[j];
        }
        stack_offset = 0;
        buffer[buffer_offset++] = str[i];
    }
    puts(buffer);
}
