// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/25 15:52.

#ifndef PBM_COS_SIMILAR_H
#define PBM_COS_SIMILAR_H

#ifdef __cplusplus
#include <string>
#endif

#ifdef __cplusplus
extern "C" {
#endif

    float cosine_similarity(const char* str1, const char* str2);

#ifdef __cplusplus
    float cos_similar(const std::string& str1, const std::string& str2);
#endif

#ifdef __cplusplus
}
#endif

#endif //PBM_COS_SIMILAR_H