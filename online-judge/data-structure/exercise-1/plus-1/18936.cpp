#include <cstdio>
#include <vector>

using namespace std;

bool invalid(const vector<unsigned> &arr, const unsigned num, const unsigned m) {
    if (arr.size() <= 1) {
        return false;
    }
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - arr[i - 1] < m) {
            return true;
        }
    }
    return num - arr.back() + arr.front() < m;
}


int main() {
    unsigned m, n, c;
    scanf("%u%u%u", &n, &m, &c);
    vector<vector<unsigned>> colors(c + 1);
    // 好ex的循环
    for (unsigned i = 0; i < n; i++) {
        unsigned num_i = 0;
        scanf("%u", &num_i);
        for (unsigned j = 0; j < num_i; j++) {
            unsigned color = 0;
            scanf("%u", &color);
            colors[color].push_back(i);
        }
    }
    unsigned cnt = 0;
    for (unsigned i = 1; i <= c; i++) {
        if (invalid(colors[i], n, m)) {
            cnt++;
        }
    }
    printf("%u\n", cnt);
}


/*
18936 手串
时间限制:1000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC

Description
字节跳动2018校招Android方向（第二批）
作为一个手串艺人，有金主向你订购了一条包含n个杂色串珠的手串——每个串珠要么无色，要么涂了若干种颜色。
为了使手串的色彩看起来不那么单调，金主要求，手串上的任意一种颜色（不包含无色），在任意连续的m个串珠里至多出现一次（注意这里手串是一个环形）。
手串上的颜色一共有c种。现在按顺时针序告诉你n个串珠的手串上，每个串珠用所包含的颜色分别有哪些。
请你判断该手串上有多少种颜色不符合要求。即询问有多少种颜色在任意连续m个串珠中出现了至少两次。



输入格式
第一行输入n，m，c三个数，用空格隔开。(1 <= n <= 10000, 1 <= m <= 1000, 1 <= c <= 50)
接下来n行每行的第一个数num_i(0 <= num_i <=
c)表示第i颗珠子有多少种颜色。接下来依次读入num_i个数字，每个数字x表示第i颗柱子上包含第x种颜色(1 <= x <= c)


输出格式
一个非负整数，表示该手链上有多少种颜色不符需求。


输入样例
5 2 3
3 1 2 3
0
2 2 3
1 2
1 3


输出样例
2


提示
第一种颜色出现在第1颗串珠，与规则无冲突。
第二种颜色分别出现在第 1，3，4颗串珠，第3颗与第4颗串珠相邻，所以不合要求。
第三种颜色分别出现在第1，3，5颗串珠，第5颗串珠的下一个是第1颗，所以不合要求。
总计有2种颜色的分布是有问题的。
这里第2颗串珠是透明的。
*/
