//
// Created by QDS on 2021/1/17.
//

#include "str.h"

static char buffer[65537];

string_t* string_new(uint16_t len)
{
    string_t* string = (string_t*)malloc(sizeof(string_t));
    if (string == NULL)
        abort();
    string->data = (uint8_t*)malloc(len);
    string->len = len;
    string->pos = 0;
    return string;
}

string_t* string_clone(const char* str)
{
    string_t* string = string_new((uint16_t)strlen(str));
    memcpy(string->data, str, string->len);
    string->pos = string->len;
    return string;

}

void string_free(string_t* string)
{
    assert(string != NULL);
    assert(string->data != NULL);
    free(string);
    free(string->data);
}

void string_printc(char c, FILE* file)
{
    assert(file != NULL);
    fwrite(&c, sizeof(char), 1, file);
}

void string_print(string_t* string, FILE* file)
{
    assert(string != NULL);
    assert(file != NULL);
    fwrite(string->data, sizeof(uint8_t), string->len, file);
}

// "hello" = 5
uint16_t string_len(string_t* string)
{
    assert(string != NULL);
    return string->len;
}

// concat("hello", "world") = "hello world"
string_t* string_concat(const string_t* lhs, const string_t* rhs)
{
    assert(lhs != NULL);
    assert(rhs != NULL);
    string_t *string = string_new(lhs->len + rhs->len);
    memcpy(string->data, lhs->data, lhs->len);
    memcpy(string->data + lhs->len, rhs->data, rhs->len);     //将内容复制到第lhs->len个字符之后
    string->pos = string->len;
    return string;
}

// left("hello world", 5) = "hello"
string_t* string_left(const string_t* lhs, uint16_t len)
{
    assert(lhs != NULL);
    assert(len > 0 && len <= lhs->len);

    string_t* string = string_new(len);
    memcpy(string->data, lhs->data, len);
    string->pos = len;
    return string;
}

// right("foo", 2) = "oo"
string_t* string_right(const string_t* rhs, uint16_t len)
{
    assert(rhs != NULL);
    assert(len > 0 && len <= rhs->len);

    string_t* string = string_new(len);
    memcpy(string->data, (rhs->data+rhs->len)-len, len);
    string->pos = len;
    return string;
}

uint16_t string_append(string_t* string, const string_t* lhs)
{
    assert(string != NULL);
    assert(lhs != NULL);

    uint16_t new_len = string->pos + lhs->len;
    if (new_len > string->len)
    {
        string->data = realloc(string->data, new_len);
        string->len = new_len;
    }
    memcpy(string->data + string->pos, lhs->data, lhs->len);
    return string->len;
}

uint16_t string_appendz(string_t* string, const char* lhs)
{
    assert(string != NULL);
    assert(lhs != NULL);

    uint16_t lhs_len = (uint16_t)strlen(lhs);
    uint16_t new_len = string->pos + lhs_len;
    if (new_len > string->len)
    {
        string->data = realloc(string->data, new_len);
        string->len = new_len;
    }
    memcpy(string->data + string->pos, lhs, lhs_len);
    return string->len;
}