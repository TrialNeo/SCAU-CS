// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/21 13:29.

#ifndef PBM_BELONG_H
#define PBM_BELONG_H
#include <stdbool.h>
#include <time.h>
struct belong {
    unsigned id;
    char name[512];
    long create_stamp; // 创建时间戳,用于排序
    char desc[512]; // 描述
    int category;//分类
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
bool belong_del(const unsigned id, const char *name, belong *deled);
void belong_del_by_category(const int category_id);
void belong_save();
bool belong_fuzzy_search(const char *name, belong_query_callback callback);
bool belong_category_search(const int category_id, belong_query_callback callback);
bool belong_category_search_no_call(const int category_id);
bool belong_id_search(unsigned id, belong_query_callback callback);
bool belong_modify(unsigned id, const char *name, const char *desc);
void belong_print_date(time_t time,belong_query_callback callback);
#endif // PBM_BELONG_H
