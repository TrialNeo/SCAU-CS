// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/4/7 19:10.

#ifndef PBM_CATEGORY_H
#define PBM_CATEGORY_H
#include <stdbool.h>
struct category {
    int id;
    char name[255];
};


typedef struct category category;
typedef struct link_category *link_category;
typedef void (*category_query_callback)(category);
struct link_category {
    category data;
    link_category next;
};
void categories_save();
bool category_add(const category data);
bool category_del(const int id);
void categories_init();
bool categories_print(category_query_callback callback);
bool category_find(const unsigned id);
#endif // PBM_CATEGORY_H
