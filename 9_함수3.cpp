// 9_함수3.cpp
#include <iostream>
using namespace std;

// 함수 오버로딩 주의 사항
void foo(int a) {}
// __Z6fooi

void foo(int a, int b) {}
// __Z6fooii

// int foo(int b) {}
// 1. 파라미터는 동일하지만, 반환타입만 다른 함수는 오버로딩이
//    불가능합니다.

// __Z6fooi

// 2. 파라미터 기본값과 함께 사용할 경우,
//    주의해야 합니다.
void goo(int a) {}
void goo(int a, int b = 10) {}

int main()
{
  // goo(); // 모호성 오류!
}