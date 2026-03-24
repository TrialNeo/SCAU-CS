// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/20.

#include "login.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/crypto.h"


typedef LOGIN_STATUS LOGIN_STATUS;

const char crypto_key[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};


//用户登录
LOGIN_STATUS password_login(const char *password) {
    //传入的是明文，我们要对此进行简单的加密，可惜不能用ECDH+Des，RSA之类的，不然还能更安全
    char *buffer = 0;
    unsigned len = 0;
    if (!encrypt(crypto_key,password, strlen(password), &buffer, &len)) {
        //这里没有成功申请内存，不用释放
        return ERROR;
    }
    FILE * file =  fopen("./password","rb"); //这个反正不是很满意
    fseek(file, 0, SEEK_END);
    unsigned len2 = ftell(file);
    rewind(file);
    if (file==NULL) {
        return PASSWORD_UNSET;
    }
    char * tmp = malloc(len2 * sizeof(char));
    fread(tmp,len2,1,file);
    //对比，由于好像没有api，直接来做吧，，
    if (len != len2) {
       fclose(file);
        free(buffer);
        free(tmp);
        return PASSWORD_INCORRECT;
    }
    bool logined = true;
    for (int i = 0;i<len;i++) {
        if (buffer[i]!= tmp[i]) {
            logined = false;
            break;
        }
    }

    free(buffer);
    free(tmp);
    fclose(file);
    if (logined) {
        return SUCCESS;
    }
    return PASSWORD_INCORRECT;
}


bool password_check_set() {
    FILE * file =  fopen("./password","rb"); //这个反正不是很满意
    if (file == NULL) {
        return false;
    }
    fseek(file, 0, SEEK_END);
    bool is_set = ftell(file) > 0;
    fclose(file);
    return is_set;
}

void password_set(const char *password) {
    FILE *file = fopen("./password", "wb");
    if (file != NULL) {
        char *buffer = 0;
        unsigned len = 0;
        if (encrypt(crypto_key,password, strlen(password), &buffer, &len)) {
            printf("%llu\n",fwrite(buffer, len, 1, file));
        }
        free(buffer);
        fclose(file);
    }
}