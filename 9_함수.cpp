// 9_함수.cpp

#include <iostream>
using namespace std;

// 기본 파라미터
//  정의: 함수의 파라미터의 기본값을 지정할 수 있습니다.
//  => 함수에 전달된 인자가 없는 경우, 컴파일러가 기본값을 자동으로 전달합니다.

// 주의사항
// 1. 반드시 마지막 파라미터부터 지정해야 합니다.
int add(int a, int b, int c = 0, int d = 0)
{
  return a + b + c + d;
}

// 2. 선언부와 구현부로 분리된 함수에서,
//    파라미터 기본값은 선언부에만 명시해야 합니다.

void foo(int a, int b, int c = 0);

int main()
{
  int result = 0;

  result = add(10, 20, 30, 40);
  cout << result << endl;

  result = add(10, 20, 30); // result = add(10, 20, 30, 0);
  cout << result << endl;

  result = add(10, 20); // result = add(10, 20, 0, 0);
  cout << result << endl;
}

void foo(int a, int b, int c /* =0 */)
{
}