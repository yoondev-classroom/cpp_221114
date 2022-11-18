// test3.c

#include <stdio.h>
#include <stdlib.h> // malloc

//  void *malloc(size_t size);

#if 0
int main()
{
  // void* -> int* : void*는 다른 포인터 타입으로의 암묵적인 변환을 허용합니다.
  int *p = malloc(sizeof(int) * 10);

  // int* -> void* : 암묵적인 캐스팅이 허용됩니다.
  void *pv = p;

  free(p);
}
#endif

int main()
{
  int n = 0;
  // ++ ++ ++n;

  printf("%d\n", ++n);
}