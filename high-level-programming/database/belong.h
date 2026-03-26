// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/21 13:29.

#ifndef PBM_BELONG_H
#define PBM_BELONG_H
#include <stdbool.h>
struct belong {
    unsigned id;
    char name[255];
    long create_stamp; // 创建时间戳,用于排序
    char desc[255]; // 描述
};

typedef struct belong belong;
struct link {
    belong *data;
    struct link *next;
};
typedef struct link *link;
typedef void (*belong_query_callback)(belong); // 分别为name,desc,time
void belong_init();
void belong_unin();
void belong_print();
bool belong_add(const belong data);
void belong_save();
void belong_fuzzy_search(const char *name, belong_query_callback callback);
#endif // PBM_BELONG_H
