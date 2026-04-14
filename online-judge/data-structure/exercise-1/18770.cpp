#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 这题和魔法那题好像差不多，我们先找到因为x在右边y在左边，要 求x-y，肯定是被减数最大 减数最小了
    //  做一个分割  我们依次找出左边的最小 右边的最大即可
    // 直接相邻的比较就行了hh
    int n = 0;
    cin >> n;

    int min_y = 0, curr = 0, max_diff = 0;
    cin >> min_y;
    for (size_t i = 1; i < n; i++) {
        cin >> curr;
        max_diff = max(max_diff, curr - min_y);
        min_y = min(min_y, curr);
    }

    cout << max_diff << endl;
    return 0;
}

/*
Description
    一个长度为N的整数序列，找出两个数x和y使x-y的值最大。
要求在序列中x必须在y的右侧。
输入格式
    第一行是一个正整数N，表示了序列的长度（0<=N<=200000）。
第二行包含N个绝对值不大于10000的整数ai。
输出格式
    一个整数，为最大的差值。数据确保结果在类型int范围内。
输入样例
    7
4 -4 3 -1 2 -4 3
输出样例
    7
*/
