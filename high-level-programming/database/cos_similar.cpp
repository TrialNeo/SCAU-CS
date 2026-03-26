// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/24 11:40.

#include "cos_similar.h"
#include <iostream>
#include <map>
#include <math.h>
using namespace std;
int getLength(string str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] < 0)
            i++;
        count++;
    }
    return count;
}

// 点乘
float dot_product(bool vector_1[], bool vector_2[], unsigned length) {
    float result = 0;
    for (unsigned i = 0; i < length; i++) {
        result += vector_1[i] * vector_2[i];
    }
    return result;
}

// 2-norm
float norm_2_bool(bool vector[], unsigned length) {
    float result = 0;
    for (int i = 0; i < length; i++) {
        result += vector[i]; // 全是0和1，不需要平方其实
    }
    return sqrtf(result);
}

float cos_similar(const std::string &str1, const std::string &str2) {
    map<string, int> vec_m;
    unsigned len_max = getLength(str1) + getLength(str2);
    bool *vec_space_1 = new bool[len_max]();
    bool *vec_space_2 = new bool[len_max]();
    unsigned count = 0;
    size_t i = 0;
    while (i < str1.size()) {
        unsigned char c = str1[i];
        int len = 1;
        if (c >= 0xF0)
            len = 4;
        else if (c >= 0xE0)
            len = 3;
        else if (c >= 0xC0)
            len = 2;

        if (vec_m.find(str1.substr(i, len)) != vec_m.end()) { // 已存在
            i += len;
            continue;
        }
        vec_m[str1.substr(i, len)] = count;
        vec_space_1[count++] = true;
        i += len;
    }
    i=0;
    while (i < str2.size()) {
        unsigned char c = str2[i];
        int len = 1;
        if (c >= 0xF0)
            len = 4;
        else if (c >= 0xE0)
            len = 3;
        else if (c >= 0xC0)
            len = 2;

        if (vec_m.find(str2.substr(i, len)) != vec_m.end()) { // 已存在
            vec_space_2[vec_m[str2.substr(i, len)]] = true;
            // continue;
        }
        i += len;
    }
    float len_1 = norm_2_bool(vec_space_1, count);
    float len_2 = norm_2_bool(vec_space_2, count);
    if (len_2 == 0) { // 一个字都匹配不上
        delete[] vec_space_1;
        delete[] vec_space_2;
        return 0;
    }

    float result = dot_product(vec_space_1, vec_space_2, count) / len_1 / len_2;

    delete[] vec_space_1;
    delete[] vec_space_2;
    return result;
}


// int main(int argc, char *argv[]) {
//     string list[] = {"《c语言从入门到精通》", "《c语言零基础到入门》", "《c语言从精通到放弃》", "秦始皇"};
//     string search = "c语言入门到精通放弃";
//     for (size_t i = 0; i < sizeof(list) / sizeof(string); i++) {
//         float r = cos_similar(list[i], search);
//         cout << list[i] << " 匹配度：" << r << endl;
//     }
// }

extern "C" {
    float cosine_similarity(const char* str1, const char* str2) {
        if (str1 == nullptr || str2 == nullptr) {
            return 0.0f;
        }
        // 调用内部的 C++ 逻辑
        return cos_similar(string(str1), string(str2));
    }
}
