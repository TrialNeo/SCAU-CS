#include <iostream>
using namespace std;

class Solution {
public:
    int smallestEvenMultiple(int n) {
        // 奇数和2的最小公倍数是他们的成绩，偶数的是是这个偶数
        if (n % 2) {
            return 2 * n;
        } else {
            return n;
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.smallestEvenMultiple(4);
    return 0;
}
