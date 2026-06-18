#include <iostream>
using namespace std;
typedef long long ll;


int main(int argc, char *argv[]) {
    ll k = 0;
    scanf("%lld", &k);
    for (ll y = k + 1; y <= 2 * k; y++) {
        const ll x = k + (k * k) / (y - k);
        if ((x-k) * (y - k) == k* k) {//看看有没有整除
            printf("1/%lld=1/%lld+1/%lld\n", k, x, y);
        }
    }
}

/*
19648 分数拆分
时间限制:1000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC

描述：
输入一个正整数，找到所有的正整数x>=y,使得1/k=1/x+1/y

输入格式：
一个正整数n，n<=100000

输出格式：
一行一个分式等式
小的分数显示在前面；多个等式，等式右边第一个分数小的先输出

输入样例：
2

输出样例：
1/2=1/6+1/3
1/2=1/4+1/4
*/
