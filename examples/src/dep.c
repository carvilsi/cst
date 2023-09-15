#include <stdio.h>

#include "dep.h"

char *variable;

int add_numbers(int x, int y)
{
        return (x + y);
}

char *give_me_a_string()
{
        return ("a string");
}

void mod_var_value(char *value)
{
        variable = value;
}

void print_variable()
{
        printf("The value of \"variable\": %s", variable);
}

