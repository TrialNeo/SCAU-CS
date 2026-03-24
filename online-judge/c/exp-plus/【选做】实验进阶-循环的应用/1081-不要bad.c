// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/24.

/*
Description
    由键盘输入一行字符（最多不超过80个字符，以回车结束），要求编程实现删除该行字符中的“bad”(小写)，输出处理后的结果(结果不含bad)。
输入格式
    一行字符
输出格式
    不含“bad”的结果
输入样例
    abadnewsisgoodnews,andbadisnotBad
输出样例
    anewsisgoodnews,andisnotBad
*/


//很自然的思路是找连续三个字节看看是不是bad，像那个卷积一样，然后把index记录下来，最后进行一下拷贝就行了 这个是不对的实现起来很麻烦，因为最后你要做一个字符串的剪切操作没有其他高级语言直接操作起来方便
//而且还会出现一个问题是：bbadad这样会出现新的bad连锁反应，我们希望再次进行检测，所以就可以使用stack，为什么不用while直接去测，删完之后再测再删。
//我的老天啊，你得准备多长的缓冲区

#include <stdio.h>
#include <string.h>

int main() {
    char input[85]; // 最多80字符 + 换行 + '\0'
    fgets(input, sizeof(input), stdin);

    // 去掉 fgets 可能读入的换行符（如果存在）
    int len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    char stack[100];
    int top = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        stack[top++] = c;
        if (top >= 3 &&
            stack[top - 3] == 'b' &&
            stack[top - 2] == 'a' &&
            stack[top - 1] == 'd') {
            top -= 3;
        }
    }
    for (int i = 0; i < top; i++) {
        putchar(stack[i]);
    }
    putchar('\n');
    return 0;
}
