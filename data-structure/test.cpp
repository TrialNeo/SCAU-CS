#include "malloc.h"
#include "stdio.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

typedef int ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

Status InsertBiTree(BiTree &T, int e) // 插入新结点
{
    if (T == NULL) {
        T = (BiTNode *) malloc(sizeof(BiTNode));
        T->data = e;
        T->lchild = NULL;
        T->rchild = NULL;
        return 1;
    }
    if (T->data < e)
        InsertBiTree(T->rchild, e);
    else
        InsertBiTree(T->lchild, e);
    return 0;
}

unsigned max(unsigned x, unsigned y) { return x > y ? x : y; }

unsigned height(BiTree &T) {
    if (!T) {
        return 0;
    }
    return max(height(T->lchild), height(T->rchild)) + 1;
}


int main() {
    int n = 0;
    scanf("%d", &n);
    BiTree t = 0;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        scanf("%d", &temp);
        InsertBiTree(t, temp);
    }
    // 二分查找
    int f = 0;
    scanf("%d", &f);
    BiTree curr = t;
    while (curr) {
        if (curr->data == f) {
            break;
        } else if (curr->data < f) {
            curr = curr->rchild;
        } else {
            curr = curr->lchild;
        }
    }
    if (curr) {
        printf("%d", height(curr));
    }
    return 0;
}
