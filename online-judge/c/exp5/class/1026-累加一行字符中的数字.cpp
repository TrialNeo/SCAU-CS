// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/14.

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    char ch;
    unsigned sum = 0;
    do {
        ch = cin.get();
        if (ch >= '0' && ch <= '9') {
           sum += ch -'0';
        }
    } while (ch!= '\n');
    cout << sum << endl;
}
