// b.c
#include <stdio.h>

void b_foo(void)
{
  printf("b foo\n");
}

int b_global = 200;
// duplicate symbol '_foo' in:
// duplicate symbol '_global' in: