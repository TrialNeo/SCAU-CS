// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/14.


#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int n = 0;
    double sum = 0,a1 = 1,a2 = 2,temp = a1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        sum+= a2 / a1;
        temp = a1;
        a1 = a2;
        a2 += temp;
    }
    cout << sum;
}
