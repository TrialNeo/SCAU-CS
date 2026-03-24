// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/26.

// Description
//     下面程序实现由函数实现求字符串长度，再填空完成
// 输入样例
//     Hello!
// 输出样例
//     6

#include "stdio.h"

// 这里用const表示没对他进行更改，只读
unsigned f(const char str[]) {
    unsigned count = 0;
    while (str[count] != 0) {
        count++;
    }
    return count;
}

int main()
{
    char s[80];
    int i;
    scanf("%s", s);
    i=f(s);
    printf("%d", i);
}