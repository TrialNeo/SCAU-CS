// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/4/28 09:40.
#include <iostream>
#include <map>
using namespace std;

map<unsigned, unsigned> memo{{0, 0}, {1, 0}, {2, 0}, {3, 1}};


// 记忆化搜索算法
unsigned dfs(const unsigned n) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    // even:1 2 3 4 : 4/2=2     1 2 3: 3/2=1...1
    // odd:even + 余数 or n - 序号为偶数的人数
    const unsigned r = dfs((n + 1) / 2) + dfs(n / 2);
    memo[n] = r;
    return r;
}

int main(int argc, char *argv[]) {
    unsigned n = 0;
    while (scanf("%u", &n) && n) {
        printf("%u\n", dfs(n));
    }
}
/*
Linear DP也是超时
int main() {
    int n = 0;
    while (scanf("%d", &n) && n) {
        vector<int> memo(n + 1, 0);
        memo[0] = memo[1] = memo[2] = 1;
        memo[3] = 0;
        for (int i = 5; i <= n; i++) {
            memo[i] = memo[i / 2] + memo[(i + 1) / 2];
        }
        printf("%d\n", memo[n]);
    }
}
*/
/*
模拟的超时了。。
vector<unsigned> out_odd(const vector<unsigned> &solids) {
    // index = 0,2,4
    vector<unsigned> arr;
    for (int i = 0; i < solids.size(); i += 2) {
        arr.push_back(solids[i]);
    }
    return arr;
}

vector<unsigned> out_even(const vector<unsigned> &solids) {
    // index = 1,3,5
    vector<unsigned> arr;
    for (int i = 1; i < solids.size(); i += 2) {
        arr.push_back(solids[i]);
    }
    return arr;
}

int out(const vector<unsigned> &solids) {
    if (solids.size() < 3) {
        return 0;
    }
    if (solids.size() == 3) {
        return 1;
    }
    return out(out_odd(solids)) + out(out_even(solids));
}
int main(int argc, char *argv[]) {
    unsigned n = 0;
    do {
        scanf("%d", &n);
        vector<unsigned> solids(n, 0);
        printf("%d\n", out(solids));
    } while (n);
}
*/


/*
Description
有N个士兵站成一队列, 现在需要选择几个士兵派去侦察。
为了选择合适的士兵, 多次进行如下操作: 如果队列超过三个士兵, 那么去除掉所有站立位置为奇数的士兵,
或者是去除掉所有站立位置为偶数的士兵。直到不超过三个战士，他们将被送去侦察。现要求统计按这样的方法，
总共可能有多少种不同的正好三个士兵去侦察的士兵组合方案。

注: 按上法得到少于三士兵的情况不统计。

1 <= N <= 2的32次方-1



输入格式
有多行（可能有上百行，尽量优化代码），每行一个数字N，最后一行是0


输出格式
对每一行的数字N，输出针对N的方案数

直到没有数字


输入样例
10
4
0


输出样例
2
0
 */
