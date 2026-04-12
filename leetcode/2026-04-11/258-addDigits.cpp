// 你可以不使用循环或者递归，在 O(1) 时间复杂度内解决这个问题吗？
#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) { return (num - 1) % 9 + 1; }
};

int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.addDigits(12);
    return 0;
}
