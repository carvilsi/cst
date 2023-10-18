# cst

<div align="center">
C Simple Test.

There are lot of c test frameworks, but this is mine.
</div>

---

1. [Introduction](#introduction)
2. [Basic Syntax](#basic-syntax)
3. [Usage](#usage)


## Introduction

Here we are trying to keep the c tests approach **simple** as possible; also trying to add some beauty to it like adding colors etc. Ok, there are some developers with a very strong negative opinion about colors at the stdout. I love colors, and most for test and logs outputs though. 

* Why re-inventing the wheel here writting another test framework for c?

**TL;DR:** Just because & 'cause it's fun.

**More long answer:** For a personal c project, I face the Eternal Return or Eternal Recurrence of the leak of test.
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

## Basic Syntax<a name="basic-syntax"/>

this will be a resume about the basic syntax

## Usage

This will be the usage block.

