// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/6/10 11:19.

#include <algorithm>
#include <iostream>
#include <vector>

// 查找跨越中点的最大子数组和
int maxCrossingSum(const std::vector<int> &arr, int low, int mid, int high) {
    // 计算包含中点向左的最大和
    int leftSum = 0;
    int maxLeftSum = -999999;
    for (int i = mid; i >= low; --i) {
        leftSum += arr[i];
        if (leftSum > maxLeftSum) {
            maxLeftSum = leftSum;
        }
    }
    // 计算包含中点向右的最大和
    int rightSum = 0;
    int maxRightSum = -999999;
    for (int i = mid + 1; i <= high; ++i) {
        rightSum += arr[i];
        if (rightSum > maxRightSum) {
            maxRightSum = rightSum;
        }
    }
    return maxLeftSum + maxRightSum;
}
// 分治法求解最大子数组和
int maxSubArraySum(const std::vector<int> &arr, int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int leftMax = 0, rightMax = 0, crossMax = 0;
    int mid = (low + high) / 2;
    leftMax = maxSubArraySum(arr, low, mid);
    rightMax = maxSubArraySum(arr, mid + 1, high); //这里什么时候应该加这个1啊？？
    crossMax = maxCrossingSum(arr, low, mid, high);
    return std::max({leftMax, rightMax, crossMax});
}
int main() {
    std::vector<int> arr;
    int n, data;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> data;
        arr.push_back(data);
    }
    int maxSum = maxSubArraySum(arr, 0, n - 1);
    std::cout << maxSum << std::endl;
    return 0;
}


/*
19639 [填空]最大子数组和问题
时间限制:1000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 填空题   语言: G++;GCC

Description
给定一个整数数组，找到一个具有最大和的连续子数组，返回其最大和，请使用分治的解法完成填空。
（注：分治法并不是解这题最快的算法，更快的DP算法能达到O(N)的复杂度，请自行了解相关知识。）


输入格式
第1行一个整数N,N<=1000
第2行N个整数，以空格分隔


输出格式
输出连续子数组最大和


输入样例
8
-2 -5 6 -2 -3 1 5 -6


输出样例
7

 */
