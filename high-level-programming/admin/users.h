// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/20.

#ifndef PBM_ADMIN
#define PBM_ADMIN
#include <stdbool.h>

// 职责
typedef enum ROLE { ROLE_USER, ROLE_ADMIN } ROLE;
struct _user {
    char username[255];
    char password[255];
    ROLE role;
};
typedef struct _user *user;
extern user global_user;

bool user_is_nil();
bool user_regist(user admin, user user_new, char *error);
bool user_login(user user, char *error);
#endif // PBM_ADMIN
