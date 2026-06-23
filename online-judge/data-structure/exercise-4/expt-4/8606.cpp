#include "malloc.h"
#include "stdio.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;

typedef char ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

Status CreateBiTree(BiTree &T) { // 算法6.4
    // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
    // 构造二叉链表表示的二叉树T。
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        T = NULL;
    else {
        if (!(T = (BiTNode *) malloc(sizeof(BiTNode))))
            return ERROR;
        T->data = ch; // 生成根结点
        CreateBiTree(T->lchild); // 构造左子树
        CreateBiTree(T->rchild); // 构造右子树
    }
    return OK;
} // CreateBiTree


Status PreOrderTraverse(BiTree T) {
    // 前序遍历二叉树T的递归算法
    // 补全代码,可用多个语句
    // 根 左 右，直接递归就行了，还用什么栈来模拟
    if (T == NULL) {
        return ERROR;
    }
    putchar(T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    return OK;
} // PreOrderTraverse

Status InOrderTraverse(BiTree T) {
    // 中序遍历二叉树T的递归算法
    // 补全代码,可用多个语句
    // 左 根 右
    if (T == NULL) {
        return ERROR;
    }
    InOrderTraverse(T->lchild);
    putchar(T->data);
    InOrderTraverse(T->rchild);
    return OK;
} // InOrderTraverse

Status PostOrderTraverse(BiTree T) {
    // 后序遍历二叉树T的递归算法
    // 补全代码,可用多个语句
    // 左 右 根
    if (T == NULL) {
        return ERROR;
    }
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    putchar(T->data);
    return OK;
} // PostOrderTraverse


int main() {
    BiTNode *T;
    CreateBiTree(T);
    PreOrderTraverse(T);
    puts("");
    InOrderTraverse(T);
    puts("");
    PostOrderTraverse(T);
    puts("");
}
