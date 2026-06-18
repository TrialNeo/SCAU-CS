#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

void traversal(const vector<ll> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        printf("%lld ", arr[i]);
    }
    putchar('\n');
}

void shell_sort(vector<ll> &arr) {
    const int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            const ll tmp = arr[i];
            int j = i;
            for (; arr[j - gap] > tmp && j >= gap; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = tmp;
        }
        traversal(arr);
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    shell_sort(arr);
}
