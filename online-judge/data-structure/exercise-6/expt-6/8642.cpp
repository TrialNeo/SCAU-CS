// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/5/27 15:19.

#include <cstdio>
#include <vector>
using namespace std;

void traversal(const vector<int> &arr) {
    int n = (int) arr.size();
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low]; // 选择基准元素（这里选择第一个元素）

    while (low < high) {
        // 分区：小于基准的元素放在左侧，大于基准的元素放在右侧
        while (low < high && pivot <= arr[high]) { // 在上一次的基础上，从右往左，找到第一个小于基准值的元素
            high--;
        }
        arr[low] = arr[high];

        while (low < high && arr[low] <= pivot) { // 在上一次的基础上，从左往右，找到第一个大于基准值的元素
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void quick_sort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot_pos = partition(arr, low, high); // 基准元素的位置
        traversal(arr);

        quick_sort(arr, low, pivot_pos - 1);
        quick_sort(arr, pivot_pos + 1, high);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, arr.size() - 1);

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
