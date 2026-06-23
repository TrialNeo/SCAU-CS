#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

void traversal(const vector<ll> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        printf("%lld ", arr[i]);
    }
    putchar('\n');
}


/**
 * @brief
 * 创建大根堆
 * @param arr
 * @param n 想要进行最大堆化的部分
 * @param node 需要操作的节点
 */
void heapify(vector<ll> &arr, int n, int node) {
    int largest = node;
    int left = 2 * node + 1;
    int right = 2 * node + 2;
    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }
    if (largest != node) {
        swap(arr[node], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(vector<ll> &arr) {
    const int len = (int) arr.size();
    for (int i = len / 2 - 1; i >= 0; i--) {
        heapify(arr, len, i);
    }
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
