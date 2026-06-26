// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/4/28 10:53.

#include <algorithm>
#include <cstdio>
using namespace std;

unsigned solve(unsigned n, unsigned head, unsigned delta) {
    if (n == 3) {
        return 0;
    }
    if (n < 3) {
        return head;
    }

    unsigned a = solve((n + 1) / 2, head, delta * 2); // 去除偶数之后不影响head
    unsigned b =
            solve(n / 2, head + delta, delta * 2); // 去除奇数之后会对head产生影响，下一次要选的应该是偶数堆里面的第一个
    return (a && b) ? min(a, b) : a | b;
}


int main() {
    unsigned n = 0;
    while (scanf("%u", &n) && n) {
        printf("%u\n", solve(n, 1, 1));
    }
    return 0;
}


/*
Description
有N个士兵站成一队列, 现在需要选择几个士兵派去侦察。
为了选择合适的士兵, 多次进行如下操作: 如果队列超过三个士兵, 那么去除掉所有站立位置为奇数的士兵,
或者是去除掉所有站立位置为偶数的士兵。直到不超过三个战士，他们将被送去侦察。现有一个“聪明”的士兵，
经常通过选择站在合适的初始位置，成功避免被选中去侦察。这引起了陈教官的注意。陈教官希望你编写一个程序，
当给定士兵数之后，输出不可能被选中去巡逻的最少编号位置（如果不存在不可能被选中的位置，则输出0）。

注: 按上法得到少于三士兵的情况不用去巡逻。

1 <= N <= 100000



输入格式
有多行（不多于20行），每行一个数字N，最后一行是0


输出格式
对每一行的数字N，不可能被选中去巡逻的最小位置

直到没有数字


输入样例
9
6
0


输出样例
2
0
 */
