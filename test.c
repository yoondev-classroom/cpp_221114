// test.c
#include <stdio.h>

void foo(void) {} // 권장!
void goo() {}

int main(void)
{
  goo(10, 20); // 컴파일 에러 X
  // foo(10, 20); // 컴파일 오류

  return 0;
  // 프로그램의 성공적인 종료를 의미합니다.
}