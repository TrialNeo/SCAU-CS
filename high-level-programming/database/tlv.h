// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/21 14:04.

#ifndef PBM_TLV_H
#define PBM_TLV_H
typedef unsigned char *bytes;

void tlv_encode_bytes(bytes *buffer, unsigned *buffer_len, unsigned length, bytes value);
void tlv_decode_bytes(bytes tlv_stream, bytes *buffer, unsigned *len);
void tlv_encode_uint(bytes *buffer, unsigned *buffer_len, unsigned long long value);
unsigned long long tlv_decode_uint(bytes tlv_stream, unsigned *len);
#endif // PBM_TLV_H
