#include <iostream>
using namespace std;
#include <math.h>
class Solution {
public:
    bool isPowerOfThree(int n) { return n > 0 && 1162261467 % n == 0; }
};


int main(int argc, char const *argv[]) {
    // 手动找一下最大的数
    // int n = 1;
    // long border = pow(2, 31);
    // while (-border < n * 3 && n * 3 < border - 1) {
    //     n *= 3;
    // }
    // cout << n;
    Solution s;

    cout << s.isPowerOfThree(45);
    return 0;
}
