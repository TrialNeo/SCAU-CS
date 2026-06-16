#include <malloc.h>
#include <stdexcept>
#include <stdio.h>

#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef struct {
    int *elem;
    int length;
    int listsize;
} SqList;

int InitList_Sq(SqList &L) {
    // 算法2.3，构造一个空的线性表L，该线性表预定义大小为LIST_INIT_SIZE
    // 请补全代码
    L.elem = (int *) malloc((sizeof(int) + 1) * LIST_INIT_SIZE);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

int Load_Sq(SqList &L) {
    // 输出顺序表中的所有元素
    int i;
    if (!L.length)
        printf("The List is empty!"); // 请填空
    else {
        printf("The List is: ");
        for (i = 1; i <= L.length; i++)
            printf("%d ", L.elem[i]); // 请填空
    }
    printf("\n");
    return OK;
}

int ListInsert_Sq(SqList &L, int i, int e) {
    // 算法2.4，在顺序线性表L中第i个位置之前插入新的元素e
    // i的合法值为1≤i≤L.length +1
    // 请补全代码
    if (i < 1 || i > L.length + 1) {
        return ERROR;
    }
    // 把后面的元素进行搬迁
    L.length++; /// 统一一下风格
    for (int j = L.length; j > i; j--) {
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[i] = e;
    return OK;
}

int ListDelete_Sq(SqList &L, int i, int &e) {
    // 算法2.5,在顺序线性表L中删除第i个位置的元素，并用e返回其值
    // i的合法值为1≤i≤L.length
    // 请补全代码
    if (i < 1 || i > L.length) {
        return ERROR;
    }
    // 往前搬迁
    e = L.elem[i];
    for (int j = i; j < L.length; j++) {
        L.elem[j] = L.elem[j + 1];
    }
    L.length--;
    return OK;
}

int main() {
    SqList T;
    int a, i;
    ElemType e, x;
    if (InitList_Sq(T)) // 判断顺序表是否创建成功
    {
        printf("A Sequence List Has Created.\n");
    }
    while (1) {
        printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
        scanf("%d", &a);
        switch (a) {
            case 1:
                scanf("%d%d", &i, &x);
                if (!ListInsert_Sq(T, i, x))
                    printf("Insert Error!\n"); // 执行插入函数，根据返回值判断i值是否合法
                else
                    printf("The Element %d is Successfully Inserted!\n", x);
                break;
            case 2:
                scanf("%d", &i);
                if (!ListDelete_Sq(T, i, e))
                    printf("Delete Error!\n"); // 执行删除函数，根据返回值判断i值是否合法
                else
                    printf("The Element %d is Successfully Deleted!\n", e);
                break;
            case 3:
                Load_Sq(T);
                break;
            case 0:
                return 1;
        }
    }
}

/*
8576 顺序线性表的基本操作
时间限制:1000MS  代码长度限制:10KB
提交次数:9027 通过次数:2456

题型: 编程题   语言: G++;GCC

Description
编写算法，创建初始化容量为LIST_INIT_SIZE的顺序表T，并实现插入、删除、遍历操作。本题目给出部分代码，请补全内容。 输入格式
测试样例格式说明：
根据菜单操作：
1、输入1，表示要实现插入操作，紧跟着要输入插入的位置和元素，用空格分开
2、输入2，表示要实现删除操作，紧跟着要输入删除的位置
3、输入3，表示要输出顺序表的所有元素
4、输入0，表示程序结束


输入样例
1
1 2
1
1 3
2
1
3
0


输出样例
A Sequence List Has Created.
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
The Element 2 is Successfully Inserted!
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
The Element 3 is Successfully Inserted!
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
The Element 3 is Successfully Deleted!
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:
The List is: 2
1:Insert element
2:Delete element
3:Load all elements
0:Exit
Please choose:


*/
