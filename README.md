<div align="center">

:ferris_wheel: Reinventing The Wheel Group presents :ferris_wheel:

C Simple Test

There are lot of c test frameworks, but this is mine.
</div>

---

# CST

1. [Introduction](#introduction)
2. [Basic Syntax](#basic-syntax)
3. [Output Example](#output-example)
4. [Usage](#usage)
5. [Long Answer](#long-answer)

## Introduction

Here we are trying to keep the c tests approach **simple** as possible; also trying to add some beauty to it like adding colors etc. Ok, there are some developers with a very strong negative opinion about colors around the terminal. I love colors, and most for test and logs outputs though. 

* Why reinventing the wheel here, writting another test framework for c?

**TL;DR:** Just because & 'cause it's fun.

For a more elaborated, but still non-sense, answer check [Long Answer](#long-answer) section.

## Basic Syntax<a name="basic-syntax"/>

### integer and string assertion

For an integer use **cst_i** for a string **cst_s** or the not equal for both **cst_i_ne** and **cst_s_ne**.

These 4 functions expects 3 arguments:

1. function_to_test()
2. "assertion text"
3. expected_value

* assert an integer

```c
//             |-> the function to test or actual value 
//             |                                |-> text for the assertion
//             |                                |                              |-> the expected value
//             |                                |                              |    
cst_i(add_numbers(2, 2), "should do addition of two numbers 2 + 2 and return", 4); 
                         
// a value different than
cst_i_ne(add_numbers(1, 1), "should do addition for 1 + 2 and return a different value than", 3);
```

* assert a string

```c
// assert a string 
cst_s(give_me_a_string(), "should give me", "a string");

// string not equal
cst_s_ne(give_me_a_string(), "should NOT give me", "foobar");
```

### raw or generic assert

Use the **cst_a** function that expects two arguments:

1. "text for the assertion"
2. a condition

* raw assert

```c
//                      |-> text for the assertion
//                      |                                          |-> the condition to test
//                      |                                          |
cst_a("the adition of 2 + 5 should retrieve 7", add_numbers(2, 5) == 7);
```

## Output example<a name"output-example"/>

<p align="center">
    <img src="https://github.com/carvilsi/cst/raw/main/img/test-output.png" alt="test-output">
</p>

## Usage

On your test file, include **cst.h** and the header files from your code that has the functions that you want to test. At the test file, call all the tests and then call the **cst_results()** function.

Under the **examples** directory you'll find the whole setup and file structure and basic usage.

The structure for testing could be something like this:

```
my_code/
├── README.md
├── src
│   ├── dep.c
│   ├── dep.h
│   └── main.c
└── tests
    ├── cst_example.c
    ├── cst.c
    ├── cst.h
    └── Makefile
```

Put **cst.c** and **cst.h** somewhere (on test folder is fine, I did not in order to not duplicate files) and point to the **cst.c** on your **Makefile** and the c files from your tests. Something like:

`$(CC) $(CCFLAGS) -o $@ $(SRC) ./../../cst.c cst_example.c $(LIBS)`

 Remember to not include your **main.c** file from your source code. This would be usefull:

`SRC := $(shell find ./../src/ -type f -name '*.c' ! -name 'main.c')` 

**tip:** reusing the **Makefile** at *examples/tests/* and modifying the **cst** files location and tests c files should do the work.

Then go to the *tests* fodler and run:

`$ make clean && make`
 
## Long Answer<a name="long-answer"/>

The **More long answer:** For a personal c project, I face the Eternal Return or Eternal Recurrence of the leak of test.
Just to ilustrate the situation consider the next sequence:

1. Starts as a fun PoC, with few lines of code. So I do not even think about writing tests, just the stuff working is a "test" itself.
2. I like it and I start cleaning the code, do some refactors.
3. I add some functionality that came out to my mind during steps 1 & 2, the lines starts growing. Still so small to write any test though.
4. I leave the project for several weeks.
5. I start working again on the personal project, I had some new ideas. More lines, more files, more functionalities, more refactoring. 
 .  The idea about having some tests starts to cross my mind; but hey still something small.
6. If I continue with the idea, I could repeat 4 and 5 several times.
7. Once again I regret myself about the absence of tests. I did not learn the lesson yet. Write the f** tests at least on step 3 or 5! 

So for first time (dealing with c) I was facing step 7 and I decided to add tests. Then; do a search on *StackOverflow*; try lot of things.
Most of the alternatives that I found required to install dependecies or was so much complicated compared with my current needs.
Suddenly I found this brilliant answer at StackOverflow site [Minunit](https://stackoverflow.com/a/65962/2191338), answer that I upvoted (of course) that leads to [JTN002 - MinUnit -- a minimal unit testing framework for C](https://jera.com/techinfo/jtns/jtn002). This whole test thingy it's based on this.



