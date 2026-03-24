// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/14.

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int array[10];
    for (int i = 0; i < 10; ++i) {
        cin >> array[i];
    }
    for (int i = 9; i >= 0; i--) {
        cout << array[i] << endl;
    }
}
