// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/20 22:26.

#include "store.h"
#include <stdio.h>
#include <stdlib.h>


const char file_crypto_key[16] = {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};


// 记得调用之后释放内存
void data_load(bytes *buffer, unsigned *size) {
    FILE *file = fopen("./data", "rb");
    // 加密的，先解密一下
    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    rewind(file);
    unsigned len = 0;
    bytes paint_text_buffer = malloc(*size);

    fread(paint_text_buffer, *size, 1, file);
    // 文件解密
    //  if (decrypt(file_crypto_key, paint_text_buffer, size, &buffer, &len)) {
    //  }
    //  free(paint_text_buffer);
    *buffer = paint_text_buffer;
    fclose(file);
}


void data_rewrite(const bytes buffer, unsigned size) {
    FILE *fp = fopen("./data", "wb");

    for (unsigned i = 0;i<size;i++) {
        printf("%02X ",buffer[i]);
    }
    putchar('\n');
    fwrite(buffer, size, 1, fp);
    fclose(fp);
}


// int main(int argc, char *argv[]) {
//     time_t current_time = time(NULL); // 获取当前时间戳
//
//     return 0;
// }
