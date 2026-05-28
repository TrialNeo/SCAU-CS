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

void bubble_sort(vector<ll> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        bool s = true;
        for (int j = 0; j < arr.size() - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                s = false;
            }
        }
        traversal(arr);
        if (s) {
            break;
        }
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    bubble_sort(arr);
}


/*

8641 冒泡排序
时间限制:1000MS  代码长度限制:10KB
提交次数:3093 通过次数:1361

题型: 编程题   语言: G++;GCC

Description
用函数实现冒泡排序，并输出每趟排序的结果(要求当一趟冒泡过程中不再有数据交换，则排序结束)



输入格式
第一行：键盘输入待排序关键的个数n
第二行：输入n个待排序关键字，用空格分隔数据


输出格式
每行输出每趟排序结果，数据之间用一个空格分隔


输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
4 5 0 8 3 2 6 7 1 9
4 0 5 3 2 6 7 1 8 9
0 4 3 2 5 6 1 7 8 9
0 3 2 4 5 1 6 7 8 9
0 2 3 4 1 5 6 7 8 9
0 2 3 1 4 5 6 7 8 9
0 2 1 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9

*/
