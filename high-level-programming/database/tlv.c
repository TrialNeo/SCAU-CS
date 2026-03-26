// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/21 14:04.

#include "tlv.h"

#include "stdlib.h"
#include "string.h"

#include "../utils/crypto.h"
#include "stdio.h"

enum TLV_TYPE { TLV_TYPE_BYTES, TLV_TYPE_UINT };


// 将belong数据流序列化为tlv数据,记得释放buffer
void tlv_encode_bytes(bytes *buffer, unsigned *buffer_len, unsigned length, bytes value) {
    if (0 < length && length <= 0b11111111) {
        *buffer_len = 2 + length;
        *buffer = malloc(*buffer_len);
        //(00010000)2  = (2^5)10
        (*buffer)[0] = TLV_TYPE_BYTES | 0b00010000;
        (*buffer)[1] = (char) (length & 0b00001111);
        memmove(*buffer + 2, value, length);
    } else if (length <= 0b1111111111111111) { // 2^16，对于现在这个玩具程序来说应该不会比这个还多的了
        *buffer_len = 3 + length;
        *buffer = malloc(*buffer_len);
        (*buffer)[0] = TLV_TYPE_BYTES | 0b00100000;
        (*buffer)[1] = (char) (length >> 8); // 0001 0001 0000 0000 => 0001 0001
        (*buffer)[2] = (char) length; //         0001 0001 0000 0000 => 0000 0000
        memmove(*buffer + 3, value, length);
    }
}

// 解成bytes，记得释放buffer
void tlv_decode_bytes(const bytes tlv_stream, bytes *buffer, unsigned *read_len,unsigned *buffer_len) {
    unsigned char bit_len = tlv_stream[0] >> 4;
    switch (bit_len) {
        case 1:
            *buffer_len = tlv_stream[1];
            break;
        case 2:
            *buffer_len = (tlv_stream[1] << 8) + tlv_stream[2];
            break;
        default:
            break;
    }
    *buffer = malloc(*buffer_len);
    memmove(*buffer, tlv_stream + 1 + bit_len, *buffer_len);
    *read_len =*buffer_len + bit_len + 1;

}

// 记得释放buffer
void tlv_encode_uint(bytes *buffer, unsigned *buffer_len, unsigned long long value) {
    unsigned char val_buffer[16] = {0}; // 考虑64位机器呢，其实想着以后还能拿出来用不只是这个作业。
    unsigned offset = 1;
    do {
        unsigned char bit = value;
        val_buffer[16 - offset++] = bit;
    } while ((value >>= 8) != 0);
    // 我们把长度直接塞到高四位去。
    *buffer = malloc(offset);
    (*buffer)[0] = ((offset - 1) << 4) | TLV_TYPE_UINT;
    *buffer_len = offset;
    offset--;
    memmove((*buffer) + 1, val_buffer + 16 - offset, offset);
}


// 读unsigned
unsigned long long tlv_decode_uint(const bytes tlv_stream, unsigned *len) {
    unsigned char length = tlv_stream[0] >> 4;
    unsigned long long result = 0;
    for (unsigned i = 1; i <= length; i++) {
        result = result << 8 | tlv_stream[i];
    }
    *len = length + 1;
    return result;
}

// void print_buffer(const unsigned char *buffer, const unsigned len) {
//     for (int i = 0; i < len; i++) {
//         printf("%02X ", buffer[i]);
//     }
//     putchar('\n');
// }
// int main(int argc, char *argv[]) {
//     unsigned char buffer[5] = {16,3,1, 2, 3};
//     unsigned len = 5;
//     // tlv_encode_uint(&buffer, &len, 123); // 0b1 1111 1111
//     // for (int i = 0; i < len; i++) {
//     //     printf("%02X ", buffer[i]);
//     // }
//     // printf("\n");
//     // printf("%llu   %d\n", tlv_decode_uint(buffer, &len), len);
//
//     unsigned char *buffer2 = 0;
//     unsigned len2 = 0,len3 = 0;
//     tlv_decode_bytes(buffer,&buffer2,&len2,&len3);
//     print_buffer(buffer2, len3);
//
//     printf("%d", len3);
//     free(buffer2);
//
// }
