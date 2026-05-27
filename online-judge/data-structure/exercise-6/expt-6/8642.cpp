// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/5/27 15:19.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
void traversal(const vector<ll> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        printf("%lld ", arr[i]);
    }
    putchar('\n');
}

inline int partition(vector<ll> &arr, const int lo, const int hi) {
    const ll pivot = arr[hi];
    int i = lo - 1;
    for (int j = lo; j < hi; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[hi]);
    return i + 1;
}


void quick_sort(vector<ll> &arr, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    const int pivot = partition(arr, lo, hi);
    quick_sort(arr, lo, pivot - 1);
    quick_sort(arr, pivot + 1, hi);
    traversal(arr);
}


int main(int argc, char *argv[]) {

    int n = 0;
    scanf("%d", &n);
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    // sort(arr.begin(),arr.end()); c++这个本身就实现了，其实可以偷懒，但是打印不出来数据，原来是这样太可恶了

    return 0;
}


/*
Description
用函数实现快速排序，并输出每次分区后排序的结果



输入格式
第一行：键盘输入待排序关键的个数n
第二行：输入n个待排序关键字，用空格分隔数据


输出格式
每行输出每趟排序的结果，数据之间用一个空格分隔


输入样例
10
5 4 8 0 9 3 2 6 7 1


输出样例
1 4 2 0 3 5 9 6 7 8
0 1 2 4 3 5 9 6 7 8
0 1 2 4 3 5 9 6 7 8
0 1 2 3 4 5 9 6 7 8
0 1 2 3 4 5 8 6 7 9
0 1 2 3 4 5 7 6 8 9
0 1 2 3 4 5 6 7 8 9


提示


作者 yqm
*/
