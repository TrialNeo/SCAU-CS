#include <algorithm>
#include <iostream>
using namespace std;

// 应该是个递归，挺简单的
int akm(unsigned m, unsigned n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return akm(m - 1, 1);
    } else { // unsigned了
        return akm(m - 1, akm(m, n - 1));
    }
}


int main(int argc, char const *argv[]) {
    int m = 0, n = 0;
    cin >> m >> n;
    cout << akm(m, n);
    return 0;
}
