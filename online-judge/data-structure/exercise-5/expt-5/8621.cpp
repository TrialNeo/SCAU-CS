#include <iostream>
#include <vector>
using namespace std;

// Search_Bin 二分查找，返回position,0开始 我们定义-1是查找失败，直接背诵就行了
int Search_Bin(vector<int> &arr, int key) {
    int mid = 0, left = 0, right = arr.size() - 1;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) { // 可能在左边
            right = mid - 1;
        } else { // 可能在左边
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int key = 0;
    scanf("%d", &key);
    int pos = Search_Bin(arr, key);
    if (pos == -1) {
        puts("The element is not exist.");
    } else {
        printf("The element position is %d.\n", pos);
    }
    return 0;
}

/*
8621 二分查找
时间限制:1000MS  代码长度限制:10KB
提交次数:4655 通过次数:1446

题型: 编程题   语言: G++;GCC

Description 编写Search_Bin函数，实现在一个递增有序数组ST中采用折半查找法确定元素位置的算法.


输入格式
第一行:元素个数n
第二行：依次输入n个元素的值（有序）
第三行：输入要查找的关键字key的值


输出格式
输出分两种情形：
1.如果key值存在，则输出其在表中的位置x(表位置从0开始),格式为The element position is x.
2.如果key值不存在输出："The element is not exist."


输入样例
6
1 3 5 7 9 10
5


输出样例
The element position is 2.

*/
