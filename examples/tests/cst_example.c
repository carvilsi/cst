#include <stdio.h>
#include <string.h>

// include the cst header file
#include "./../../cst.h"

// inlude the non-main file that you want to test
#include "./../src/dep.h"

// the tests

static void add_numbers_()
{
        // here you do the assert in this case for a integer
        //
        //             |-> the function to test or actual value 
        //             |                                |-> text for the assertion
        //             |                                |                                 |-> the expected value
        //             |                                |                                 |    
        cst_i(add_numbers(2, 2), "should do an addition of two numbers 2 + 2 and return", 4); 
                                 
        // you can add here more cases
        cst_i(add_numbers(1, 2), "should do an addition of two numbers 1 + 2 and return", 3); 
                                 
        // and this one will fail
        cst_i(add_numbers(2, 3), "should do an addition of two numbers 2 + 3 and return", 4); 
                                 
        // you can add here more cases
        cst_i(add_numbers(1, 2), "should do an addition of two numbers 1 + 2 and return", 3); 

        // a value different than
        cst_i_ne(add_numbers(1, 1), "should do an addition of two numbers 1 + 2 and return a different value than", 3); 
}

static void give_me_a_string_()
{
        // assert a string 
        cst_s(give_me_a_string(), "should give me", "a string");

        // goingt to fail
        cst_s(give_me_a_string(), "should give me", "foobar");

        // string not equal
        cst_s_ne(give_me_a_string(), "should NOT give me", "foobar");
}

static void variable_value_()
{
        mod_var_value("foobar");
        cst_s(variable, "should be", "foobar");
        mod_var_value("lol&stock");
        cst_s(variable, "should be", "foobar");
        mod_var_value("foobarbaz");
        cst_s(variable, "should be", "foobarbaz");
}

static void raw_assert()
{

        // This is a raw assertion way
        //
        //                      |-> text for the assertion
        //                      |                                          |-> the condition to test
        //                      |                                          |
        cst_a("the adition of 2 + 5 should retrieve 7", add_numbers(2, 5) == 7);

        mod_var_value("foobar");
        cst_a("the variable should be 'foobar'", strcmp(variable, "foobar") == 0);

        // this will fail
        cst_a("the variable should be 'foobar'", strcmp(variable, "foobarlol") == 0);

}
// bundle all your tests could be a good idea
static void all_the_tests()
{
        cst_run(add_numbers_);
        cst_run(give_me_a_string_);
        cst_run(variable_value_);
        cst_run(raw_assert);
}

int main()
{
        // run the tests
        all_the_tests();

        // get the results
        cst_results();
}

