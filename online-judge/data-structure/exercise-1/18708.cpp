#include <algorithm>
#include <iostream>
using namespace std;


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N = 0;
    cin >> N;
    // 上一个最大然后找找会不会变小？？如果变小了当前这个数也是不能要的
    for (size_t i = 0; i < N; i++) {
    }


    return 0;
}


/*
Description
    一个整数序列，选出其中连续且非空的一段使得这段和最大。
输入格式
    第一行是一个正整数N，表示了序列的长度（0=<N<=200000）。
    第二行包含N个绝对值不大于10000的整数ai。
输出格式
    一个整数，为最大的子段和。子段的最小长度为1。数据确保结果在类型int范围内。
输入样例
7
2 -4 3 -1 2 -4 3
输出样例
4
提示
【样例说明】
2,-4,3,-1,2,-4,3中，最大的子段和为4，该子段为第三元素至第五元素，即3,-1,2。
*/
