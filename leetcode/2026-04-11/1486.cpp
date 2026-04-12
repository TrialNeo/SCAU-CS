#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;
        for (size_t i = 0; i < n; i++) {
            res ^= start + i * 2;
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.xorOperation(5, 0);
    return 0;
}
