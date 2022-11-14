// add.c
#include <stdio.h>

int add(int a, int b)
{
  printf("C - add\n");
  return a + b;
}

/*
0000000000000000 T _add
                 U _printf

*/

// $ gcc add.c -c