// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/24.
/*Description
编写程序，由键盘输入3个整数，输出其中最大的数。
输入格式
    三个整数，空格分隔
输出格式
    最大的数
输入样例
    3 6 4
输出样例
    6
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    a = a>b?a:b;
    a = a>c?a:c;
    printf("%d",a);
}
