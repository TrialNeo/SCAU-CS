// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/20.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// 可以复用的链表hh，写出来然后后面复制修改修改就行了
struct link {
    int data;
    struct link* next;
};
typedef struct link *link;

link link_init(unsigned num) {
    //头结点
    link L = (link)malloc(sizeof(struct link));
    if (L== NULL) {
        return NULL;
    }
    L->data = 0;
    L->next = NULL;
    link p = L;
    for (int i = 1;i<=num;i++) {
        link node = malloc(sizeof(struct link));
        node->next = NULL;
        node->data = i;
        p->next = node;
        p = node;
    }
    return L;
}

//直接释放所有链表，头结点也不例外
void link_free(link L) {
    link p = L->next,q = NULL;
    while (p!= NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    L->next = NULL;
    free(L);
}


//打印列表
void link_print(link L) {
    link p = L->next;
    while (p != NULL) {
        printf("%d ",p->data);
        p = p->next;
    }
    putchar('\n');
}

//在index之前插入，比如说(1,2,3)=[1,2,3],insert(L,1,4) => (1,2,3,4)=[4,1,2,3]
bool link_insert_with_id(link L, const int index, const int data) {
    //直接头部插入
    if (index == 1) {
        link node = malloc(sizeof(struct link));
        if (node == NULL) {
            return false;
        }
        node->next = L->next;
        node->data = data;
        L->next =node;
        return true;
    }
    link p = L;
    int i = 1;
    for (;i<index && p!= NULL;i++) {
        p=p->next;
    }
    if (i == index && p!= NULL) {
        link node = malloc(sizeof(struct link));
        if (node == NULL) {
            return false;
        }
        node->next = p->next;
        node->data = data;
        p->next = node;
        return true;
    }
    return false;
}

//升序排序的插入,前提是本来的顺序就是升序的，其实和link_insert_with_id优点矛盾
bool link_insert_with_sort(link L, const int data) {
    link p =L;
    while (p->next!= NULL && data > p->next->data ) {
        p = p->next;
    }
    link node = malloc(sizeof(struct link));
    if (node == NULL) {
        return false;
    }
    node->next = p->next;
    node->data = data;
    p->next = node;
    return true;
}

//删除指定index的节点
bool link_del(link L,int index) {
    if (L->next == NULL) {
        return false;
    }
    link p = L;
    int count = 1;
    for (;count<index && p!=NULL;count++) {
        p= p->next;
    }
    //都到尾巴了怎么删除emm，压根没有这个元素好吗
    if (p!= NULL && p->next != NULL) {
        link temp = p->next;
        p->next = temp->next;
        free(temp);
        return true;
    }
    return false;
}

//插入排序
bool link_sort(link *L) {
    if ((*L)->next == NULL) {
        //空表默认就是有序的。。
        return true;
    }
    if ((*L)->next->next == NULL) {
        //只有一个元素的也是不需要排序的，本来就有序
        return true;
    }
    link new = malloc(sizeof(struct link));
    new->data = 0;
    new->next = NULL;
    if (new ==NULL) {
        return false;
    }
    link p = (*L)->next;
    while (p!=NULL) {
        link_insert_with_sort(new, p->data);
        p = p->next;
    }
    free(*L);
    *L = new;
    return true;
}

int main(int argc, char *argv[]) {
    unsigned n = 0;
    scanf("%u",&n);
    link t = 0;
    t = link_init(n);
    link_print(t);
    link_insert_with_sort(t, 0);
    link_print(t);


    link_insert_with_id(t,3,9);
    link_print(t);

    link_del(t, 5);
    link_print(t);

    link_sort(&t);
    link_print(t);


    link_free(t);
}
