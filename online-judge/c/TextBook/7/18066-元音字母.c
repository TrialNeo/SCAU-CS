// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/2.

// Description
//     编写一个函数，挑选一个字符串中的所有元音字母构成并返回一个新的字符串
// 输入格式
//     由键盘输入一行字符，以'\n'结束
// 输出格式
//     输出新构成的字符串
// 输入样例
//     I am good
// 输出样例
//     Iaoo
// 提示
//     元音字母有a、e、i、o、u，这5个元音字母，大写或小写

#include "stdio.h"

void yuan(char *s, char *s2) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                s2[count++] = s[i];
                break;
            default:
                break;
        }
    }
    s2[count] = '\0';
}


void yuan2(char *s, char *s2) {
    static const int v[128] = {
        ['a'] = 1, ['e'] = 1, ['i'] = 1, ['o'] = 1, ['u'] = 1,
        ['A'] = 1, ['E'] = 1, ['I'] = 1, ['O'] = 1, ['U'] = 1,
    };
    char ch = 0;
    //!= '\0' 0=='\0' 省略了
    while ((ch = *(s++)) ) {
        if (v[ch]) {
            *(s2++) = ch;
        }
    }
    *s2 = '\0';
}

int main() {
    char str[81], str2[81];
    gets(str);
    yuan2(str, str2);
    printf("%s", str2);
}
