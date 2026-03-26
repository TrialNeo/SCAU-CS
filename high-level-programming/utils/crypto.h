// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/20.

#ifndef crypto
#define crypto
#include <stdbool.h>
bool decrypt(const char key_buffer[16],const char *paint_text_buffer, unsigned text_len, char **buffer,unsigned *len);
bool encrypt(const char key_buffer[16],const char *paint_text_buffer, unsigned text_len,char **buffer,unsigned *len);
void print_buffer(const unsigned char *buffer,const unsigned len);
#endif