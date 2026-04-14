#include <iostream>
using namespace std;
#include <algorithm>


// https://cloud.tencent.com/developer/article/2617354 这篇文章告诉我们
int gcd(unsigned a, unsigned b) {
    if (a < b) {
        swap(a, b);
    }
    // 辗转相除法
    unsigned m = 0;
while (true)
{
    /* code */
}

    return m;
}

int main(int argc, char const *argv[]) {
    cout << gcd(21, 28);

    return 0;
}
