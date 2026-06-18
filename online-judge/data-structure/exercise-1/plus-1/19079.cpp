#include <iostream> //C++
using namespace std;
struct LNode {
    int data;
    LNode *next;
};
void createList(LNode *&L, int n) { /**< 尾插法创建单链表 */
    LNode *r, *p;
    r = L = new LNode; /**< 创建头结点 */
    L->next = NULL;
    for (int i = 1; i <= n; i++) {
        p = new LNode;
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}
void trv(LNode *L) { /**< 一个简单的链表遍历函数，供编程过程中测试使用 */
    L = L->next;
    while (L) {
        cout << L->data << ' ';
        L = L->next;
    }
}
int getK(LNode *L, int k) {
    LNode *arr[100] = {0};
    int cnt = 0;
    LNode *p = L->next;
    while (p) {
        arr[cnt++] = p;
        p = p->next;
    }
    if (k <= cnt) {
        return arr[cnt - k]->data;
    }
    return -1;
}
int main() {
    int n, k;
    LNode *L;
    cin >> n >> k;
    createList(L, n);
    // trv(L);
    cout << getK(L, k);
    return 0;
}
