// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/20 22:26.

#ifndef SCAU_OJ2_STORE_H
#define SCAU_OJ2_STORE_H
#include "tlv.h"
void data_load(bytes *buffer, unsigned *size);
void data_load_category(bytes *buffer_category, unsigned *size_category);
void data_rewrite_belongs(bytes buffer, unsigned size);
void data_rewrite_category(const bytes buffer, unsigned size);
#endif // SCAU_OJ2_STORE_H
