// 13_캐스팅.cpp
#include <iostream>

#include <cstdlib>
using namespace std;

// 명시적인 캐스팅을 많이 사용합니다.

// 수정할 수 없는 이전에 만들어진 함수
void print_str(char *s)
{
  printf("%s\n", s);
}

// C 캐스팅의 문제점
// > 어떤 목적으로 사용하는지 파악하기 어렵다.
// => 용도와 목적에 따라서 4가지의 캐스팅 연산자를 제공합니다.
#if 0
int main()
{
  // void*를 다른 포인터 타입으로의 암묵적인 변환이 허용되지 않습니다.
  // => 명시적인 캐스팅이 필요합니다.
  int *p = (int *)malloc(sizeof(int) * 10);

  // 다른 포인터 타입을 void*로의 암묵적인 캐스팅은 허용됩니다.
  void *pv = p;

  // double을 int로 초기화하는 일관된 초기화에서 명시적인 캐스팅이 필요합니다.
  double d = 3.14;
  int n1{(int)d};

  // long long을 int로 초기화하는 구문에서 명시적인 캐스팅이 필요합니다.
  long long l = 1000LL;
  int n2{(int)l};

  // 메모리 재해석
  int n = 0x12345678;
  char *pn = (char *)&n; // int* -> char*
  printf("%x %x %x %x\n", pn[0], pn[1], pn[2], pn[3]);

  /* 위험한 코드 */
  double *pd = (double *)&n;
  *pd = 3.14; /* 미정의 동작 */

  // 타입의 불일치(const)
  const char *str = "hello world";
  print_str((char *)str); // const char* -> char* 암묵적인 변환 허용 X
}
#endif

// 1. static_cast
//  : 가장 기본적인 C++ 캐스팅 연산자 입니다.
//    연관성 있는 타입간의 캐스팅에서 사용할 수 있습니다. => 합리적인 캐스팅
//       double -> int
//    long long -> int
//       void*  -> T*
//  => 컴파일 타임에 캐스팅을 수행하기 때문에, static_cast 입니다.

// 2. reinterpret_cast
//   : 메모리 재해석 용도로 사용합니다.
//  => 메모리를 재해석하는 것은 위험성을 내포하므로,
//     주의해서 사용해야 한다는 의도가 있습니다.

// 3. const_cast
//   : 메모리의 상수성/휘발성을 제거하는 목적으로 사용합니다.
//     const/volatile의 타입의 불일치 문제를 해결하는 용도로 사용해야 합니다.

// 4. dynamic_cast
//   : 다운 캐스팅을 위해서 사용됩니다.
//     실행 시간에 타입을 조사해서, 캐스팅을 수행하고, 잘못된 타입인 경우
//     nullptr을 반환합니다.

int main()
{
  // int *p1 = (int *)malloc(sizeof(int) * 10);
  int *p1 = static_cast<int *>(malloc(sizeof(int) * 10));

  double d = 3.14;
  int n1{static_cast<int>(d)};

  long long l = 1000LL;
  int n2{static_cast<int>(l)};

  // 메모리 재해석
  int n = 0x12345678;
  // char *pn = static_cast<char *>(&n); /* Compile Error */
  char *pn = reinterpret_cast<char *>(&n); /* OK */
  printf("%x %x %x %x\n", pn[0], pn[1], pn[2], pn[3]);

  // double *pd = static_cast<double *>(&n);      /* Compile Error */
  double *pd = reinterpret_cast<double *>(&n); /* OK */
  // *pd = 3.14;                               /* 미정의 동작 */

  const char *str = "hello world";
  // print_str(str);

  // print_str(static_cast<char *>(str));      /* Compile Error */
  // print_str(reinterpret_cast<char *>(str)); /* Compile Error */
  print_str(const_cast<char *>(str));

  volatile int n3 = 100; // 캐싱 최적화 금지 => 메모리 가시성 문제를 해결하기 위한 키워드
  // int *pn2 = static_cast<int *>(&n3);
  // int *pn2 = reinterpret_cast<int *>(&n3);
  int *pn2 = const_cast<int *>(&n3);
}