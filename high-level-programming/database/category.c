// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/4/6 21:42.
// 这个分类就不用链表了用顺序表，链表不得不说还是很难用

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"
#include "category.h"

#include "../system/system.h"
#include "belong.h"


link_category m_link_categories;
unsigned m_size_category = 0;


link_category link_init_category() {
    // 头结点
    link_category L = malloc(sizeof(struct link_category));
    if (L == NULL) {
        return NULL;
    }
    L->next = NULL;
    return L;
}

// 直接释放所有链表，头结点也不例外
void link_free_category(link_category L) {
    link_category p = L->next, q = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    L->next = NULL;
    free(L);
}

// 升序排序的插入,前提是本来的顺序就是升序的，其实和link_insert_with_id优点矛盾
bool link_insert_with_sort_category(link_category L, const category data) {
    link_category p = L;
    while (p->next != NULL && data.id > p->next->data.id) {
        p = p->next;
    }
    const link_category node = calloc(1, sizeof(struct link_category));
    if (node == NULL) {
        return false;
    }
    node->next = p->next;
    node->data = data;
    p->next = node;
    return true;
}

// 删除指定index的节点
bool link_del_category(link_category L, int index) {
    if (index < 1) {
        return false;
    }
    if (L->next == NULL) {
        return false;
    }
    link_category p = L;
    int count = 1;
    for (; count < index && p != NULL; count++) {
        p = p->next;
    }
    // 都到尾巴了怎么删除emm，压根没有这个元素好吗
    if (p != NULL && p->next != NULL) {
        link_category temp = p->next;
        p->next = temp->next;
        free(temp);
        return true;
    }
    return false;
}

// 插入排序
bool link_sort_category(link_category *L) {
    if ((*L)->next == NULL) {
        // 空表默认就是有序的。。
        return true;
    }
    if ((*L)->next->next == NULL) {
        // 只有一个元素的也是不需要排序的，本来就有序
        return true;
    }
    link_category new = calloc(1, sizeof(struct link_category));
    new->next = NULL;
    if (new == NULL) {
        return false;
    }
    link_category p = (*L)->next, q = NULL;
    while (p != NULL) {
        q = p->next;
        link_insert_with_sort_category(new, p->data);
        free(q);
        p = p->next;
    }
    free(*L);
    *L = new;
    return true;
}

//categories_save 保存分类，和belongs同款加密
void categories_save() {
    if (m_link_categories == NULL) {
        return;
    }

    link_category p = m_link_categories->next;
    unsigned char *w_buffer = malloc(5148), *buffer = 0;
    // 123456
    unsigned offset = 0, len_written = 0;

    tlv_encode_uint(&buffer, &len_written, m_size_category);
    memmove(w_buffer, buffer, len_written);
    offset = len_written;
    free(buffer);

    while (p != NULL) {
        tlv_encode_uint(&buffer, &len_written, p->data.id);
        memmove(w_buffer + offset, buffer, len_written);
        free(buffer);
        offset += len_written;

        tlv_encode_bytes(&buffer, &len_written, strlen(p->data.name), (unsigned char *) p->data.name);
        memmove(w_buffer + offset, buffer, len_written);
        free(buffer);
        offset += len_written;


        p = p->next;
    }

    data_rewrite_category(w_buffer, offset);
    free(w_buffer);
}

//category_find 查找有没有这个
bool category_find(const unsigned id) {
    link_category p = m_link_categories->next;
    while (p!=NULL) {
        if (p->data.id == id) {
            return true;
        }
        p = p->next;
    }
    return false;
}


//category_add 这个data无需自己申请内存
bool category_add(category data) {
    data.id=++ m_size_category;
    return link_insert_with_sort_category(m_link_categories, data);
}

//根据id删除指定的分类
bool category_del(const int id) {
    link_category p = m_link_categories->next,q = m_link_categories;
    while (p!=NULL) {
        if (p->data.id == id) {
            belong_del_by_category(id);
            q->next = p->next;
            free(p);
            m_size_category--;
            return true;
        }
        q = p;
        p = p->next;
    }
    return false;
}


// 初始化
void categories_init() {
    m_link_categories = link_init_category();
    bytes buffer = 0;
    unsigned buffer_size = 0, len_read = 0, buffer_len = 0, offset = 0;
    // 读取持久化配置
    data_load_category(&buffer, &buffer_size);
    if (buffer_size == 0) {
        return;
    }

    unsigned block_num = tlv_decode_uint(buffer, &len_read);
    bytes buffer_read = 0;
    offset += len_read;


    for (unsigned i = 0; i < block_num; i++) {
        category data = {0};

        data.id = tlv_decode_uint(buffer + offset, &len_read);
        offset += len_read;

        tlv_decode_bytes(buffer + offset, &buffer_read, &len_read, &buffer_len);
        memcpy(data.name, buffer_read, buffer_len);
        free(buffer_read);
        offset += len_read;

        category_add(data);
    }
    free(buffer);
}

//遍历全部的分类，调用callback进行回调
bool categories_print(category_query_callback callback) {
    if (m_size_category== 0) {
        return false;
    }
    link_category p = m_link_categories->next;
    while (p != NULL) {
        callback(p->data);
        p = p->next;
    }
    return true;
}