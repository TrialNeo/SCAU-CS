// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/21 13:04.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "belong.h"
#include <string.h>


link belongs;
unsigned size = 0;


link link_init(unsigned num) {
    // 头结点
    link L = malloc(sizeof(struct link));
    if (L == NULL) {
        return NULL;
    }
    L->next = NULL;
    link p = L;
    for (int i = 1; i <= num; i++) {
        link node = malloc(sizeof(struct link));
        node->next = NULL;
        // node->data = NULL;
        p->next = node;
        p = node;
    }
    return L;
}

// 直接释放所有链表，头结点也不例外
void link_free(link L) {
    if (L== NULL) {
        return;
    }
    link p = L->next, q = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q->data);
        free(q);
    }
    L->next = NULL;
    free(L);
}


// 升序排序的插入,前提是本来的顺序就是升序的，其实和link_insert_with_id优点矛盾
bool link_insert_with_sort(link L, const belong data) {
    link p = L;
    while (p->next != NULL && data.create_stamp > p->next->data->create_stamp) {
        p = p->next;
    }
    link node = malloc(sizeof(struct link));
    if (node == NULL) {
        return false;
    }
    node->next = p->next;
    node->data = malloc(sizeof(belong));
    strcpy(node->data->name,data.name);
    strcpy(node->data->desc,data.desc);
    node->data->create_stamp = data.create_stamp;
    p->next = node;
    return true;
}

// 删除指定index的节点
bool link_del(link L, int index) {
    if (index < 1) {
        return false;
    }
    if (L->next == NULL) {
        return false;
    }
    link p = L;
    for (int count = 1; count < index && p != NULL; count++) {
        p = p->next;
    }
    // 都到尾巴了怎么删除emm，压根没有这个元素好吗
    if (p != NULL && p->next != NULL) {
        const link temp = p->next;
        p->next = temp->next;
        free(temp);
        return true;
    }
    return false;
}

//初始化
void belong_init() {
    belongs = link_init(0);
}


//卸载，释放内存
void belong_unin() {
    link_free(belongs);
}

//录入新的物品
bool belong_add(const belong data) {
    return link_insert_with_sort(belongs,data);
}

//按照一定格式打印物品，顺序为%s%s%d=>name desc time
void belong_print(belong_query_callback callback) {
    link p = belongs->next;
    while (p != NULL) {
        callback(*(p->data));
        p = p->next;
    }
}

void belong_save() {
    link p = belongs->next;
    while (p != NULL) {

        p = p->next;
    }
}

// void a(const belong data) {
//     printf("%s %s %ld\n",data.name,data.desc,data.create_stamp);
// }
//
// int main(int argc, char *argv[]) {
//     belong_init();
//     belong data ;
//     strcpy(data.name,"asihdsa");
//     strcpy(data.desc,"uihshdsai");
//     data.create_stamp = time(NULL);
//     belong_add(data);
//     belong_print(a);
//
//     belong_unin();
// }
