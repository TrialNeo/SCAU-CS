#include <algorithm>
#include <iostream>
using namespace std;


unsigned gcd(unsigned x, unsigned y) {
    if (x < y) {
        swap(x, y);
    }
    while (y) {
        int t = y;
        y = x % y;
        x = t;
    }
    return x;
}


int main() { printf("%d", gcd(3, 6)); }
