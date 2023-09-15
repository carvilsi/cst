#include <stdio.h>

#include "dep.h"

int main()
{
        printf("The result of add: %d\n", add_numbers(2, 2));
        printf("Give me: %s\n", give_me_a_string());

        char *var = "The world is all that is the case\n";
        mod_var_value(var);
        print_variable();
        
        return 0;
}

