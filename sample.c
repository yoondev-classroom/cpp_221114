// sample.c

#include <stdio.h>

#include "sample.h"

int main(void)
{
  int result = add(10, 20);

  printf("%d\n", result);

  return 0;
}

// $ gcc sample.c -c
// $ g++ add.cpp -c
// $ g++ sample.o add.o

/*
Undefined symbols for architecture x86_64:
  "_add", referenced from:
      _main in sample.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)

// sample.o
                 U _add
0000000000000000 T _main

// add.o
0000000000000000 T __Z3addii

0000000000000000 T _add

*/