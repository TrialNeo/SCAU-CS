#include <iostream>
#include <vector>
using namespace std;
// 这个是前面的插入排序的查找改成二分查找，其实有现成的查询语句可以用

typedef long long ll;

void traversal(const vector<ll> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        printf("%lld ", arr[i]);
    }
    putchar('\n');
}

void binary_insertion_sort(vector<ll> &arr) {
    const int n = arr.size();
    for (int i = 1; i < n; i++) {
        const ll tmp = arr[i];
        int left = 0, right = n - 1;
        while (left < right) {
            const int mid = (left + right) / 2;
            if (arr[mid] < tmp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }
        arr[left] = tmp;
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
    binary_insertion_sort(arr);
}

/*
8639 折半插入排序
时间限制:1000MS  代码长度限制:10KB
提交次数:1738 通过次数:1371

题型: 编程题   语言: G++;GCC

Description
用函数实现折半插入排序，并输出每趟排序的结果.



输入格式
第一行：键盘输入待排序关键的个数n
第二行：输入n个待排序关键字，用空格分隔数据


输出格式
每行输出一趟排序结果，数据之间用一个空格分隔


输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
4 5 8 0 9 3 2 6 7 1
4 5 8 0 9 3 2 6 7 1
0 4 5 8 9 3 2 6 7 1
0 4 5 8 9 3 2 6 7 1
0 3 4 5 8 9 2 6 7 1
0 2 3 4 5 8 9 6 7 1
0 2 3 4 5 6 8 9 7 1
0 2 3 4 5 6 7 8 9 1
0 1 2 3 4 5 6 7 8 9
*/
