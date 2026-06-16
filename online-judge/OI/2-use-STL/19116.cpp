#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
// 这个居然在力扣做过，默写题了

typedef long long ll;


vector<ll> pre_ugly_num(const unsigned size) {
    vector<ll> dp(size + 1);
    dp[1] = 1; // 把第一个位置空出来
    unsigned p2 = 1, p3 = 1, p5 = 1;
    for (size_t i = 2; i <= size; i++) {
        ll next_2 = dp[p2] * 2;
        ll next_3 = dp[p3] * 3;
        ll next_5 = dp[p5] * 5;
        ll next_ugly = min({next_2, next_3, next_5});

        dp[i] = next_ugly;
        if (next_ugly == next_2) {
            p2++;
        }
        if (next_ugly == next_3) {
            p3++;
        }
        if (next_ugly == next_5) {
            p5++;
        }
    }
    return dp;
}


int main(int argc, char const *argv[]) {
    const vector<ll> pre = pre_ugly_num(10000);
    unsigned n = 0;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        unsigned id = 0;
        scanf("%u", &id);
        printf("%lld\n", pre[id]);
    }

    return 0;
}


/* Description
“丑数”是指除了质因子2,3，5，不含其它质因子的正整数，例如由小到大前10个“丑数”为
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, ...
现要求编写一个程序，输出指定第几位的“丑数”。



输入格式
第一行为正整数T（T<=10000）, 表示case的数目。
此后T行，每行一个正整数 n (确定该第n个凑数不超过1000000000).


输出格式
每一个n，输出第n个“丑数”


输入样例
3
1
2
9


输出样例
1
2
10

*/
