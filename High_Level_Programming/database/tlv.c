// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/21 14:04.

#include "tlv.h"

#include "stdlib.h"
#include "string.h"

enum TLV_TYPE { TLV_TYPE_BYTES, TLV_TYPE_UINT32 };


#include <stdio.h>

// 将belong数据流序列化为tlv数据,记得释放buffer
void tlv_encode_bytes(unsigned char **buffer, unsigned *buffer_len, unsigned char type, unsigned length,
                      unsigned char *value) {
    if (0 < length && length <= 0b11111111) {
        *buffer_len = 2 + length;
        *buffer = malloc(*buffer_len);
        //(00010000)2  = (2^5)10
        (*buffer)[0] = type | 0b00010000;
        (*buffer)[1] = (char) (length & 0b00001111);
        memmove(*buffer + 2, value, length);
    } else if (length <= 0b1111111111111111) { // 2^16，对于现在这个玩具程序来说应该不会比这个还多的了
        *buffer_len = 3 + length;
        *buffer = malloc(*buffer_len);
        (*buffer)[0] = type | 0b00100000;
        (*buffer)[1] = (char) (length >> 8); // 0001 0001 0000 0000 => 0001 0001
        (*buffer)[2] = (char) length; //         0001 0001 0000 0000 => 0000 0000
        memmove(*buffer + 3, value, length);
    }
}

void tlv_encode_uint32(unsigned char **buffer, unsigned *buffer_len, unsigned char type, unsigned length,
                       unsigned int value) {}

// 将数据流序列化为普通数据
void tlv_decode_(void *buffer, const unsigned char *tlv_stream) {
    printf("%d\n", tlv_stream[0]);
    char type = tlv_stream[0] & 0b00001111;
    switch (type) {
        case TLV_TYPE_BYTES:
            unsigned char bit_len = tlv_stream[0] >> 4;
            unsigned len = 0;
            switch (bit_len) {
                case 1:
                    len = tlv_stream[1];
                    break;
                case 2:
                    len = (tlv_stream[1] << 8) + tlv_stream[2];
                    break;
                default:
                    break;
            }
            unsigned char *b = malloc(len);
            memmove(b, tlv_stream + 1 + bit_len, len);
            for (int i = 0; i < len; i++) {
                printf("%d ", b[i]);
            }
            break;
        default:
            break;
    }
}

int main(int argc, char *argv[]) {
    printf("%d", 0b10000000 >> 4);

    unsigned char *
            test = "在C语言中，printf() "
                   "函数是我们常用的输出函数，但它并没有直接提供输出二进制数的格式说明符，不过，我们可以通过一些技巧来"
                   "实现二进制的输出。本文将介绍 3 种方法C 的标准 printf 函数不直接支持 %b "
                   "这样的二进制格式说明符，但是C 的标准 printf 函数不直接支持 %b "
                   "这样的二进制格式说明符，但是有一些变通方法可以实现这个功能。通过循环和位操作打印整数的二进制格式。"
                   "这种方法适用于所有平台，不依赖于任何非标准库。有一些变通方法可以实现这个功能。通过循环和位操作打印"
                   "整数的二进制格式。这种方法适用于所有平台，不依赖于任何非标准库。来使用 printf() 函数输出二进制数。",
           *buffer = 0;
    unsigned buffer_len = 0;
    tlv_encode_bytes(&buffer, &buffer_len, TLV_TYPE_BYTES, strlen(test), test);
    printf("%llu\n", sizeof(buffer));
    for (int i = 0; i < buffer_len; i++) {
        printf("%d ", buffer[i]);
    }
    puts("");
    tlv_decode_(NULL, buffer);
}
