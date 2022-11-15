// add.c
#include <stdio.h>

int add(int a, int b)
{
  printf("C - add\n");
  return a + b;
}

const int c = 100;

/*
0000000000000000 T _add
0000000000000034 S _c    => external linkage
                 U _printf

*/

// $ gcc add.c -c