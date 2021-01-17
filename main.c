#include "str.h"

int main(int argc, char** argv)
{
    string_t* hello_world  = string_clone("HELLO WORLD");
    string_print(hello_world, stdout);
    string_free(hello_world);

    fprintf(stdout, "\nlen=%d\n", string_len(hello_world));

    string_t* hello = string_left(hello_world, 5);
    string_print(hello, stdout);
    string_free(hello);

    fprintf(stdout, "\n");

    string_t* world = string_right(hello_world, 5);
    string_print(world, stdout);
    string_free(world);

    fprintf(stdout, "\n");

    string_t* str_concat = string_concat(hello, world);
    string_print(str_concat, stdout);
    string_free(str_concat);
    return 0;
}
