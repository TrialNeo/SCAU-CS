// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/20.

#ifndef PBM_ADMIN
#define PBM_ADMIN
#include <stdbool.h>
enum LOGIN_STATUS {
    SUCCESS,
    PASSWORD_INCORRECT,
    ERROR,
    PASSWORD_UNSET
};
typedef enum LOGIN_STATUS LOGIN_STATUS;
LOGIN_STATUS password_login(const char *password);
bool password_check_set();
void password_set(const char *password);
#endif //PBM_ADMIN