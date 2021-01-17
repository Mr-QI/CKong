//
// Created by QDS on 2021/1/17.
//

#include "str.h"
string_t* string_clone(const char* str)
{
    string_t* string = (string_t*)malloc(sizeof(string_t));
    if (string == NULL)
        abort();
    string->data = (uint8_t*)strdup(str);
    string->len =  (uint16_t)strlen(str);
    return string;

}

string_t* string_new(uint16_t len)
{
    string_t* string = (string_t*)malloc(sizeof(string_t));
    if (string == NULL)
        abort();
    string->data = (uint8_t*)malloc(len);
    string->len = len;
    return string;
}


void string_free(string_t* string)
{
    assert(string != NULL);
    assert(string->data != NULL);
    free(string);
}

void string_print(string_t* string, FILE* file)
{
    assert(string != NULL);
    assert(file != NULL);
    static char buffer[65537];
    memcpy(&buffer, string->data, string->len);
    buffer[string->len] = '\0';
    fprintf(file, "%s" ,buffer);
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
    string_t *string = (string_t*)malloc(sizeof(string_t));
    string->data = (uint8_t*)malloc(lhs->len + rhs->len);
    string->len = lhs->len + rhs->len;
    memcpy(string->data, lhs->data, lhs->len);
    memcpy(string->data + lhs->len, rhs->data, rhs->len);     //将内容复制到第lhs->len个字符之后
    return string;
}

// left("hello world", 5) = "hello"
string_t* string_left(const string_t* lhs, uint16_t len)
{
    assert(lhs != NULL);
    assert(len > 0 && len <= lhs->len);
    string_t* string = (string_t*)malloc(sizeof(string_t));
    string->data = (uint8_t*)malloc(len);
    string->len = len;
    memcpy(string->data, lhs->data, len);
    return string;
}

// right("foo", 2) = "oo"
string_t* string_right(const string_t* rhs, uint16_t len)
{
    assert(rhs != NULL);
    assert(len > 0 && len <= rhs->len);
    string_t* string = (string_t*)malloc(sizeof(string_t));
    string->data = (uint8_t*)malloc(len);
    string->len = len;
    memcpy(string->data, (rhs->data+rhs->len)-len, len);
    return string;
}