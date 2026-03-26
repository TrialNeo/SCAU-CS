// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/21 13:04.

#include "belong.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cos_similar.h"
#include "store.h"
#include "tlv.h"

link belongs;
unsigned m_size = 0;


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
    if (L == NULL) {
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
    node->data->id = m_size++;
    strcpy(node->data->name, data.name);
    strcpy(node->data->desc, data.desc);
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


//---------------------------------------------------------------------


void belong_save() {
    link p = belongs->next;
    unsigned char *w_buffer = malloc(5148), *buffer = 0;
    // 123456
    unsigned offset = 0, len_written = 0;

    tlv_encode_uint(&buffer, &len_written, m_size);
    memmove(w_buffer, buffer, len_written);
    offset = len_written;

    free(buffer);


    while (p != NULL) {
        tlv_encode_uint(&buffer, &len_written, p->data->id);
        memmove(w_buffer + offset, buffer, len_written);
        free(buffer);
        offset += len_written;


        tlv_encode_uint(&buffer, &len_written, p->data->create_stamp);
        memmove(w_buffer + offset, buffer, len_written);
        free(buffer);
        offset += len_written;


        tlv_encode_bytes(&buffer, &len_written, strlen(p->data->name), (unsigned char *) p->data->name);
        memmove(w_buffer + offset, buffer, len_written);
        free(buffer);
        offset += len_written;


        tlv_encode_bytes(&buffer, &len_written, strlen(p->data->desc), (unsigned char *) p->data->desc);
        memmove(w_buffer + offset, buffer, len_written);
        offset += len_written;
        free(buffer);

        p = p->next;
    }

    data_rewrite(w_buffer, offset);
    free(w_buffer);
}


// 初始化
void belong_init() {
    belongs = link_init(0);
    bytes buffer = 0;
    unsigned len = 0, len_read = 0, offset = 0;
    // 读取持久化配置
    data_load(&buffer, &len);
    if (len == 0) {
        return;
    }

    unsigned size = tlv_decode_uint(buffer, &len_read);
    bytes buffer_read = 0;
    offset += len_read;


    for (unsigned i = 0; i < size; i++) {
        belong data;
        data.id = tlv_decode_uint(buffer + offset, &len_read);
        offset += len_read;

        data.create_stamp = tlv_decode_uint(buffer + offset, &len_read);
        offset += len_read;

        tlv_decode_bytes(buffer + offset, &buffer_read, &len_read);
        memcpy(data.name, buffer_read, len_read);
        free(buffer_read);

        offset += len_read;


        tlv_decode_bytes(buffer + offset, &buffer_read, &len_read);
        memcpy(&data.desc, buffer_read, len_read);
        free(buffer_read);
        offset += len_read;

        belong_add(data);
    }
    free(buffer);
}


// 卸载，释放内存
void belong_unin() { link_free(belongs); }

// 录入新的物品
bool belong_add(const belong data) { return link_insert_with_sort(belongs, data); }

// 按照一定格式打印物品，顺序为%s%s%d=>name desc time
void belong_print(belong_query_callback callback) {
    link p = belongs->next;
    while (p != NULL) {
        callback(*(p->data));
        p = p->next;
    }
}


// 通过cosine similarity算法进行模糊搜索
void belong_fuzzy_search(const char *name, belong_query_callback callback) {
    // 相似度最大值
    static const float SIMILARITY_THRESHOLD = 0.3;

    typedef struct {
        belong data;
        float similarity;
    } similarity_item;

    link p = belongs->next;

    // 分配内存存储相似度数据
    similarity_item *items = malloc(sizeof(similarity_item) * m_size);
    if (items == NULL) {
        return;
    }

    // 计算每个物品的相似度
    int index = 0;
    while (p != NULL && index < m_size) {
        items[index].data = *(p->data);
        items[index].similarity = cosine_similarity(name, p->data->name);
        index++;
        p = p->next;
    }

    // 按照相似度降序排列
    for (int i = 0; i < m_size - 1; i++) {
        for (int j = i + 1; j < m_size; j++) {
            if (items[i].similarity < items[j].similarity) {
                similarity_item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    // 显示相似度高于阈值的物品
    for (int i = 0; i < m_size; i++) {
        if (items[i].similarity >= SIMILARITY_THRESHOLD) {
            callback(items[i].data);
        }
    }
    // 释放内存
    free(items);
}
