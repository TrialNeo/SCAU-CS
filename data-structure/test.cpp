#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;


void traversal(const vector<ll> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

void _sort(vector<ll> &arr) {
    ll m = 0;
    for (int i = 0; i < arr.size(); i++) {
        m = arr[i];
        int k = 0;
        for (int j = i + 1; j < arr.size(); i++) {
            if (arr[j] < m) {
                        }
        }
    }
}


int main() {
    int n = 0;
    scanf("%d", &n);
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    _sort(arr);
}
