#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>


using namespace std;

typedef struct {
    int num;
    int cnt;
} m;

bool cmp(const m &x, const m &y) {

    if (x.cnt == y.cnt) {
        return x.num < y.num;
    }
    return x.cnt > y.cnt;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    map<int, int> memo;
    vector<m> arr;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        scanf("%d", &temp);
        memo[temp]++;
    }
    for (auto key: memo) {
        m temp = {key.first, key.second};
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < min((int) arr.size(), 3); i++) {
        printf("%d %d\n", arr[i].num, arr[i].cnt);
    }
}

/*
14  统计数出现的次数
Time Limit:1000MS  Memory Limit:65535K

题型: 编程题   语言: G++;GCC

描述：
输入N个整数（1<=N<=1000,
每个整数的绝对值不超过1000），统计不同数出现的次数，根据出现的次数由多到少，输出出现次数排前3的数和次数，如果次数相同，则先输出数小的。（注：如果不同的数不足3个，则按题目要求的顺序全部输出）

输入格式：
第1行是一个整数N（1<=N<=1000）
第2行是N个整数，由空格分隔

输出格式：
一行一个数和该数出现的次数，以一个半角空格分隔

输入样例：
6
5 1 5 3 1 7

输出样例：
1 2
5 2
3 1
*/
