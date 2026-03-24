// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/18.

#include<stdio.h>
#include<malloc.h>
#include <iostream>
#define ERROR 0
#define OK 1
#define ElemType int
using namespace std;

typedef int Status;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;


Status ListInsert_L(LinkList &L, int i, ElemType e) {
    // 算法2.9
    // 在带头结点的单链线性表L的第i个元素之前插入元素e
    LinkList p, s;
    p = L;
    int j = 0;
    while (p && j < i - 1) {
        // 寻找第i-1个结点
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR; // i小于1或者大于表长
    s = (LinkList) malloc(sizeof(LNode)); // 生成新结点
    s->data = e;
    s->next = p->next; // 插入L中
    p->next = s;
    return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e) {
    // 算法2.10
    // 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
    LinkList p, q;
    p = L;
    int j = 0;
    while (p->next && j < i - 1) {
        // 寻找第i个结点，并令p指向其前趋
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1) return ERROR; // 删除位置不合理
    q = p->next;
    p->next = q->next; // 删除并释放结点
    e = q->data;
    free(q);
    return OK;
}

Status LinkInit(LinkList &L, int size) {
    L = new LNode;
    L->next = nullptr;
    L->data = 0;
    LinkList p = L;
    int temp = 0;
    for (int i = 0; i < size; i++) {
        scanf("%d", &temp);
        LNode *node = new LNode;
        node->next = nullptr;
        node->data = temp;
        p->next = node;
        p = node;
    }
    return OK;
}

Status LinkPrint(LinkList &L, string name) {
    if (L->next == nullptr) {
        return ERROR;
    }
    LinkList p = L->next;
    cout << "List " << name << ":";
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    return OK;
}


Status LinkMerge(LinkList &z, LinkList &x, LinkList &y) {
    //交叉对比，具体实现不知道会不会有诈
    LinkList p_z = z,
            p_x = x,
            p_y = y;
    int count_x = 0,count_y = 0,count_z = 0;

    //问题是这两东西怎么交叉比较？？两个while嵌套？直接做一个查找函数算了，不过性能太低了


}


int main(int argc, char *argv[]) {
    LinkList L1, L2, L3;
    int n;
    std::cin >> n;
    LinkInit(L1, n);
    std::cin >> n;
    LinkInit(L2, n);
    LinkPrint(L1, "A");
    LinkPrint(L2, "B");
    LinkMerge(L3, L1, L2);
    LinkPrint(L3, "C");

}
