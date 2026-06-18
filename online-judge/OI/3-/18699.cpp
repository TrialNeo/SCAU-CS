// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/4/28 11:24.


#include <iostream>
using namespace std;

void merge_sort(int *A, int x, int y, int *T) {
    if (y - x > 1) {
        const unsigned m = (x + y) / 2;
        merge_sort(A, x, m, T);
        merge_sort(A, m, y, T);

        int p = x, q = m, i = x;
        while (p < m || q < y) {
            if (q >= y || (p < m && A[p] <= A[q]))
                T[i++] = A[p++];
            else
                T[i++] = A[q++];
        }
        for (i = x; i < y; i++)
            A[i] = T[i];
    }
}

int main() {
    int n;
    int data[1001];
    int temp[1001];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> data[i];
    merge_sort(data, 0, n, temp);
    for (int i = 0; i < n; i++)
        cout << data[i] << endl;
}

/*
Description
从键盘输入N个数，使用归并排序进行排序后，由小到大输出。
输入格式
第一行，第一个数是N（N<1000）
第二行，N个数，空格分隔
输出格式
由小到大输出一行一个数
输入样例
6
1 2 3 6 5 4
输出样例
1
2
3
4
5
6
*/
