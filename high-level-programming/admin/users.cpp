// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/29 15:41.

#include "users.h"
#include <string>

#include "../database/tlv.h"
using namespace std;

// 职责
enum ROLE {
    ROLE_ADMIN,
    ROLE_USER
};

struct user {
    string username;
    string password;
    ROLE role;
} ;
typedef struct user user;
const char crypto_key[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};


//通过管理员注册一个账号，气笑了不敢用类,怕扣大分
bool user_regist(user admin,string new_username,string new_password,string &error) {
    //先鉴权
    if (admin.role != ROLE_ADMIN) {
        error = "权限不足";
        return false;
    }
    //查找有无该用户的存在
    string file_path = "/data/users/"+new_username;
    FILE *fp = fopen(file_path.c_str(),"rb");
    if (fp!= NULL) {
        fclose(fp);
        error = "该用户已存在，无法注册";
        return false;
    }
    //真的要注册了
    char * buffer = 0;
    unsigned buffer_len = 0;
    if (!encrypt(crypto_key, new_password.c_str(), new_password.length(), &buffer, &buffer_len)) {
        error = "密码加密失败";
        return false;
    }

    fp = fopen(file_path.c_str(),"wb");
    fwrite(buffer,buffer_len,1,fp);//写入密码
    fclose(fp);
    return true;
}


bool user_login(user user,string &error) {
    //传入的是明文，我们要对此进行简单的加密，可惜不能用ECDH+Des，RSA之类的，不然还能更安全
    char *buffer = 0;
    unsigned len = 0;
    if (!encrypt(crypto_key,user.password.c_str(), user.password.length(), &buffer, &len)) {
        //这里没有成功申请内存，不用释放
        return ERROR;
    }
    const string file_path = "/data/users/"+user.username;
    FILE * file =  fopen("./password","rb"); //这个反正不是很满意
    if (file==NULL) {
        return PASSWORD_UNSET;
    }
    fseek(file, 0, SEEK_END);
    unsigned len2 = ftell(file);
    rewind(file);
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


//获取用户列表
