// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/5.
//
// Description
//     下面程序，先创建一个链表，然后调用reverse函数，将链表中各结点变为倒序排列。请完成reverse函数，
// 输入样例
// 3
// 1
// 98
// 4
// 99
// 5
// 87
//
// 输出样例
//     1      98
//     4      99
//     5      87
//     5      87
//     4      99
//     1      98

#include <locale.h>

#include "stdio.h"
#include "malloc.h"
#define LEN sizeof(struct student)

struct student {
    long num;
    int score;
    struct student *next;
};

struct student *create_circle(int n) {
    struct student *head = NULL, *p1 = NULL, *p2 = NULL;
    int i;
    for (i = 1; i <= n; i++) {
        p1 = (struct student *) malloc(LEN);
        scanf("%ld", &p1->num);
        scanf("%d", &p1->score);
        p1->next = NULL;
        if (i == 1) head = p1;
        else p2->next = p1;
        p2 = p1;
    }
    return (head);
}

void print(struct student *head) {
    struct student *p;
    p = head;
    while (p != NULL) {
        printf("%8ld%8d", p->num, p->score);
        p = p->next;
        printf("\n");
    }
}

struct student *reverse(struct student *head) {
    //用一个栈给他全部存起来然后，然后这个思路是不行的；你不知道整个链表的长度
    //那我往下看一个就改一次，不就行了吗，类似于二阶递推公式
    if (!head || !head->next) {
        return head;
    }
    struct student *prev = NULL, *curr = head, *nxt = head->next;
    while (curr) {
        curr -> next = prev;
        prev = curr;
        curr = nxt;
        nxt = curr->next;
    }
    return curr;
}

int main() {
    struct student *head, *stu;
    int n;
    scanf("%d", &n);
    head = create_circle(n);
    print(head);
    head = reverse(head);
    print(head);
}
