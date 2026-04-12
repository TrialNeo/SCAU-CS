#include <iostream>
using namespace std;
class Solution {
public:
    int subtractProductAndSum(int n) {
        long long product = 1;
        int sum = 0;
        do {
            int tmp = n % 10;
            product *= tmp;
            sum += tmp;
            n /= 10;
        } while (n != 0);
        // 各位数字的积不知道有没有
        return product - sum;
    }
};


int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.subtractProductAndSum(4421);
    return 0;
}
