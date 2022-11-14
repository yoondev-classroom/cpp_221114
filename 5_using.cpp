// 5_using.cpp
#include <iostream>
using namespace std;

// using
// 1. namespace
//   - using 선언
//     using std::cout;
//     using std::cin;

//   - using 지시어
//     using namespace std;

// 2. C++11, 기존 타입의 별칭을 만들 때 사용할 수 있습니다.
//   => typedef를 대체합니다.

foo()
{
  static int x[3];
  return x;
}

goo()
{
  static int x[3];
  return &x;
}

int main()
{
  int n;
  // n의 타입은 int 입니다.
  // => 식별자(n)를 제외한 나머지가 타입입니다.

  int x[3] = {10, 20, 30};
  // x의 타입은 무엇인가요?
  // => int[3]

  // 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석된다.
  // => Decay
  // 예외
  //   1) sizeof
  printf("%zu\n", sizeof(x));
  printf("%zu\n", sizeof(int[3]));

  int *p = x; // &x[0];
  printf("%zu\n", sizeof(p));
  printf("%zu\n", sizeof(&x[0]));

  //  2) &
  int(*p2)[3] = &x; // x -> Decay X -> int[3]
  // 배열 포인터
}