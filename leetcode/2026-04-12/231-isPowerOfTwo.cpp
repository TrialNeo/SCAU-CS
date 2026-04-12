#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if (n == 0) {
        //     return false;
        // }
        // // 最简单直接的方法
        // while (n != 1) {
        //     if (n % 2) {
        //         return false;
        //     }
        //     n >>= 1;
        // }
        // return true;
        return n > 0 && !(n & (n - 1));
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.isPowerOfTwo(0);
    cout << s.isPowerOfTwo(1);
    cout << s.isPowerOfTwo(2);
    cout << s.isPowerOfTwo(4);
    cout << s.isPowerOfTwo(8);
    return 0;
}
