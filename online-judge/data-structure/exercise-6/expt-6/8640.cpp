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

void heap_sort(vector<ll> &arr) {
    const int n = arr.size();
    // 按照增量进行分组
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对每个子列表进行插入排序
        for (int i = gap; i < n; i++) {
            int j = i;
            const auto key = arr[j];
            // 满足前面的比 key 大才要进行插入排序嘛，很简单的道理；这个 j >= gap 是为了防止越界，越到外面去了；
            for (; arr[j - gap] > key && j >= gap; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = key;
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
    heap_sort(arr);
}
