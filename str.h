//
// Created by QDS on 2021/1/17.
//

#ifndef CKONG_STR_H
#define CKONG_STR_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct str{
    uint16_t len;
    uint8_t* data;
}string_t;

string_t* string_clone(const char* str);

string_t* string_new(uint16_t len);

void string_free(string_t* string);

uint16_t string_len(string_t* string);

void string_print(string_t* string, FILE* file);

string_t* string_left(const string_t* lhs, uint16_t len);

string_t* string_right(const string_t* rhs, uint16_t len);

string_t* string_concat(const string_t* lhs, const string_t* rhs);


#endif //CKONG_STR_H
