// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/5.

// Description
//     有n个人围成一圈，从第1个人开始报数1、2、3，每报到3的人退出圈子。编程使用链表找出最后留下的人。
// 输入格式
//     输入一个数n，1000000>=n>0
// 输出格式
//     输出最后留下的人的编号
// 输入样例
//     3
// 输出样例
//     2


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int ID;
    struct Node *next;
};

typedef struct Node node;

struct Node *create_circle(int num) {
    node *head = NULL,
            *new = NULL,
            *current = malloc(sizeof(node));
    if (num >= 1) {
        head = current;
        current->ID = 1;
        current->next = NULL;
    }
    for (int i = 2; i <= num; i++) {
        new = malloc(sizeof(node));
        new->ID = i;
        new->next = NULL;
        current->next = new;
        current = new;
    }
    current->next = head;
    return head;
}


int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);
    node *current = create_circle(n);

    printf("%d", current->ID);

}
