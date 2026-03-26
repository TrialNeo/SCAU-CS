// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/20 22:26.

#include "store.h"
#include <stdio.h>
#include <stdlib.h>

#include "../system/system.h"
#include "../utils/crypto.h"


const char file_crypto_key[16] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
void data_load(bytes *buffer, unsigned *size) {
    FILE *file = fopen("./data", "rb");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        unsigned len = ftell(file);
        rewind(file);
        bytes paint_text_buffer = malloc(len);
        fread(paint_text_buffer, len, 1, file);
        // 文件解密
        decrypt(file_crypto_key, (char *) paint_text_buffer, len, (char **) buffer, size);
        // print_buffer(*buffer,*size);
        free(paint_text_buffer);
        fclose(file);
    }
}


// 记得调用之后释放buffer的内存
void data_rewrite(const bytes buffer, unsigned size) {
    FILE *fp = fopen("./data", "wb");
    // print_buffer(buffer, size);
    char *_buffer = 0;
    unsigned len = 0;
    if (encrypt(file_crypto_key, buffer, size, &_buffer, &len)) {
        fwrite(_buffer, len, 1, fp);
        fclose(fp);
        free(_buffer);
    }
}


// int main(int argc, char *argv[]) {
//     time_t current_time = time(NULL); // 获取当前时间戳
//
//     return 0;
// }
