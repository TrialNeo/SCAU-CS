// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/29 15:41.

#include "users.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/crypto.h"
const char crypto_key[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
user global_user;

bool user_regist(user admin, user user_new, char *error) {
    if (admin->role != ROLE_ADMIN) {
        strcpy(error, "权限不足");
        return false;
    }
    // 写入密码
    char file_path[1024];
    snprintf(file_path, sizeof(file_path), "./data/users/%s", user_new->username);
    FILE *fp = fopen(file_path, "rb");
    if (fp != NULL) {
        fclose(fp);
        strcpy(error, "该用户已存在，无法注册");
        return false;
    }
    fclose(fp);
    char *buffer = NULL;
    unsigned buffer_len = 0;
    if (!encrypt(crypto_key, user_new->password, strlen(user_new->password), &buffer, &buffer_len)) {
        strcpy(error, "密码加密失败");
        return false;
    }
    fp = fopen(file_path, "wb");
    fwrite(buffer, 1, buffer_len, fp);
    fclose(fp);
    free(buffer);

    // 写入ROLE，这个不加密
    snprintf(file_path, sizeof(file_path), "./data/users/%s.ROLE", user_new->username);
    fp = fopen(file_path, "wb");
    fprintf(fp, "%d", user_new->role);
    fclose(fp);
    return true;
}

bool user_login(user user, char *error) {
    char file_path[1024];
    snprintf(file_path, sizeof(file_path), "./data/users/%s", user->username);
    // system_tip(file_path);
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        strcpy(error, "该用户不存在");
        return false;
    }

    char *buffer = NULL;
    unsigned len = 0;
    if (!encrypt(crypto_key, user->password, strlen(user->password), &buffer, &len)) {
        strcpy(error, "密码加密失败");
        fclose(file);
        return false;
    }

    fseek(file, 0, SEEK_END);
    long len2 = ftell(file);
    rewind(file);
    if ((long) len != len2) {
        free(buffer);
        fclose(file);
        strcpy(error, "密码错误");
        return false;
    }
    char *tmp = malloc(len2);
    fread(tmp, 1, len2, file);
    bool login_status = true;
    for (int i = 0; i < (int) len; i++) {
        if (buffer[i] != tmp[i]) {
            login_status = false;
            break;
        }
    }
    free(buffer);
    free(tmp);
    fclose(file);
    if (login_status) {
        snprintf(file_path, sizeof(file_path), "./data/users/%s.ROLE", user->username);
        FILE *fp = fopen(file_path, "rb");
        // fread(&user->role, 1, 1, fp);
        fscanf(fp, "%d", &user->role);
        fclose(fp);
        return true;
    }
    strcpy(error, "密码错误");
    return false;
}

bool user_is_nil() {
    DIR *d = opendir("./data/users");
    if (d == NULL) {
        return true;
    }
    struct dirent *entry;
    int found = 0;
    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            found = 1;
            break;
        }
    }
    closedir(d);
    return !found;
}
