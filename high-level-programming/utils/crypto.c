// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/20.


#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 加密函数，加密成功后在buffer,len进行修改；这里会申请一大片缓冲区，记得去释放
// 详细可以看Handbook of applied cryptography这本书的1.5的一个example，这里我们推广成16的倍数，具体就是对着这里实现的
bool encrypt(const char key_buffer[16], const char *paint_text_buffer, const unsigned text_len, char **buffer,
             unsigned *len) {
    // 排除空数据，空秘钥
    if (key_buffer == NULL || paint_text_buffer == NULL || text_len == 0) {
        return false;
    }
    // 先分块，并且计算填充
    unsigned block_leave = 16 - text_len % 16;
    unsigned block_num = (text_len / 16) + (block_leave > 0);
    unsigned block_size = sizeof(char) * 16 * block_num;
    // 申请一块16*block_num的缓冲区用来放加密后的数据，再来一个计数器
    // 然后做一个填充
    int offset = 0;
    *buffer = (char *) malloc(block_size);
    memcpy(*buffer, paint_text_buffer, text_len);
    // padding 这个用的是pkcs#7
    for (int i = 1; i <= block_leave; i++) {
        (*buffer)[block_size - i] = block_leave;
    }
    // for (int i = 0;i<block_size;i++) {
    //     printf("%2d ",(*buffer)[i]);
    // }
    // putchar('\n');
    // for (int i = 0;i<16;i++) {
    //     printf("%2d ",key_buffer[i]);
    // }
    // putchar('\n');
    for (int i = 0; i < block_num; ++i) {
        for (int j = 0; j < 16; j++) {
            (*buffer)[offset++] ^= key_buffer[j];
            // printf("%2d ",(*buffer)[offset]);
        }
    }
    *len = block_size;
    return true;
}

void print_buffer(const unsigned char *buffer,const unsigned len) {
    for (int i = 0; i < len; i++) {
        printf("%02X ", buffer[i]);
    }
    putchar('\n');
}
// 解密，记得释放内存
bool decrypt(const char key_buffer[16], char *paint_text_buffer, const unsigned text_len, char **buffer,
             unsigned *len) {
    // 排除密文居然不是16的倍数，秘钥居然不是16位的，还有一些空的神奇事情
    if (key_buffer == NULL || paint_text_buffer == NULL || text_len == 0 || text_len % 16) {
        return false;
    }
    // 和上面的相同的
    unsigned block_num = text_len / 16;
    *buffer = (char *) malloc(text_len);
    unsigned offset = 0;
    memcpy(*buffer, paint_text_buffer, text_len);
    for (int i = 0; i < block_num; ++i) {
        for (int j = 0; j < 16; ++j) {
            (*buffer)[offset++] ^= key_buffer[j];
        }
    }

    // 倒找填充字节
    unsigned padding = (*buffer)[offset - 1];
    bool is_padding = true;
    for (int i = 1; i <= padding; i++) {
        if ((*buffer)[offset - i] != padding) {
            is_padding = false;
            break;
        }
    }
    if (is_padding) {
        *len = text_len - padding;
    } else {
        *len = text_len;
    }
    return true;
}

//
// int main(int argc, char *argv[]) {
//     char key[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//     char text[] = {1, 2, 3, 4, 5, 6};
//     // char enc_text = {0,0,0,0,0,0,13,2,3,0,1,6,7,4,5,26};
//     char *buffer = 0, *buffer2 = 0;
//     unsigned len = 0, len2 = 0;
//     encrypt(key, text, 6, &buffer, &len);
//     print_buffer(buffer, len);
//     decrypt(key, buffer, len, &buffer2, &len2);
//     printf("%d  %d\n",len,len2);
//     print_buffer(buffer2, len2);
//     free(buffer);
//     free(buffer2);
// }
