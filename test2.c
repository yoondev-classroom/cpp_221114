// test2.c

// $ gcc test2.c -c
// $ nm test2.o
/*
// 핵심: C의 함수는 인자 정보가 이름에 포함되지 않습니다.
void foo(void)
 0000000000000000 T _foo


void foo(int a, int b)
 0000000000000000 T _foo
*/

void foo(int a, int b)
{
}

int main(void)
{
  return 0;
}