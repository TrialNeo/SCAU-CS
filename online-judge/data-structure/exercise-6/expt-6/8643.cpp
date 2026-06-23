#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

void traversal(const vector<ll> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        printf("%lld ", arr[i]);
    }
    putchar('\n');
}

void heap_sort(vector<ll> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        auto min_idx = i;
        for (int j = i; j < arr.size(); j++) {
            if (arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
        traversal(arr);
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    heap_sort(arr);
}

/*
8643 简单选择排序
时间限制:1000MS  代码长度限制:10KB
提交次数:2235 通过次数:1301

题型: 编程题   语言: G++;GCC

Description
用函数实现简单选择排序，并输出每趟排序的结果



输入格式
第一行：键盘输入待排序关键的个数n
第二行：输入n个待排序关键字，用空格分隔数据


输出格式
每行输出每趟排序的结果，数据之间用一个空格分隔


输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
0 4 8 5 9 3 2 6 7 1
0 1 8 5 9 3 2 6 7 4
0 1 2 5 9 3 8 6 7 4
0 1 2 3 9 5 8 6 7 4
0 1 2 3 4 5 8 6 7 9
0 1 2 3 4 5 8 6 7 9
0 1 2 3 4 5 6 8 7 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9

*/
