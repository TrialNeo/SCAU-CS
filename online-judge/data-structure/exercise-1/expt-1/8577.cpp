#include <cstdio>
#include <vector>
using namespace std;


vector<int> merge(vector<int> &a, vector<int> &b) {
    // 这里其实可以偷懒 直接sort，没人管，但是还是算了直接双指针
    auto len_a = a.size(), len_b = b.size(), len_res = len_a + len_b;
    vector<int> res(len_res, 0);
    int p = 0, q = 0, k = 0;
    while (p < len_a && q < len_b && k < len_res) {
        if (a[p] < b[q]) {
            res[k++] = a[p++];
        } else {
            res[k++] = b[q++];
        }
    }
    while (p < len_a) {
        res[k++] = a[p++];
    }
    while (q < len_b) {
        res[k++] = b[q++];
    }
    return res;
}

void traversal(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

vector<int> input() {
    int n = 0;
    scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int main() {
    vector<int> a = input();
    printf("List A:");
    traversal(a);
    vector<int> b = input();
    printf("List B:");
    traversal(b);
    printf("List C:");
    vector<int> c = merge(a, b);
    traversal(c);
}


/*
Description
若线性表中数据元素相互之间可以比较，且数据元素在表中按值递增或递减，则称该表为有序表。

编写算法，将两个非递减有序顺序表A和B合并成一个新的非递减有序顺序表C。



输入格式
第一行：顺序表A的元素个数
第二行：顺序表A的各元素（非递减），用空格分开
第三行：顺序表B的元素个数
第四行：顺序表B的各元素（非递减），用空格分开


输出格式
第一行：顺序表A的元素列表
第二行：顺序表B的元素列表
第三行：合并后顺序表C的元素列表


输入样例
5
1 3 5 7 9
5
2 4 6 8 10


输出样例
List A:1 3 5 7 9
List B:2 4 6 8 10
List C:1 2 3 4 5 6 7 8 9 10


提示
输出时注意大小写和标点。
*/
