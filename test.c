// test.c
#include <stdio.h>

#if 0
void foo(void) {} // 권장!
void goo() {}

int main(void)
{
  goo(10, 20); // 컴파일 에러 X
  // foo(10, 20); // 컴파일 오류

  return 0;
  // 프로그램의 성공적인 종료를 의미합니다.
}
#endif

#if 0
int main(void)
{
  const int c; // OK
  // c = 10;   // Compile Error
  printf("%d\n", c);
}
#endif

int main(void)
{
  char str1[] = "hello";
  const char *str2 = "hello";

  str1[0] = 'x';
  // str2[0] = 'x'; /* 미정의 동작 */
}