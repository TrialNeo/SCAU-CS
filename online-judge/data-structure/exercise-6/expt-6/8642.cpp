// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/5/27 15:19.

#include <iostream>
using namespace std;

int n;
int arr[1001];

void printArr() {
    for (int i = 0; i < n; i++) {
        if (i > 0)
            cout << " ";
        cout << arr[i];
    }
    cout << "\n";
}

// Lomuto 分区，首元素为 pivot
int partition(int low, int high) {
    int pivot = arr[low];
    int i = low;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[low]);
    return i; // pivot 最终下标
}

void quicksort(int low, int high) {
    if (low >= high)
        return; // 长度 0 或 1，不打印
    int p = partition(low, high);
    printArr(); // 分区完成后立即打印
    quicksort(low, p - 1); // 递归左子区间
    quicksort(p + 1, high); // 递归右子区间
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quicksort(0, n - 1);
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
