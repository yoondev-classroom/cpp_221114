// 9_함수7.cpp
#include <iostream>
using namespace std;

// 최대 공약수 함수
//  => 정수에서만 사용되어야 하는 함수입니다.
int gcd(int a, int b)
{
  return b != 0 ? gcd(b, a % b) : a;
}

// 위의 함수에 대해서 오직 정수에서만 사용되고, 정수가 아닐 경우
// 금지하고 싶습니다.

// 1) 구현을 제공하지 않고, 선언만 제공합니다. => 링크 오류
//   - 문제의 원인을 찾기 어렵습니다.
//   - 의도를 전달하기 어렵습니다.
//  double gcd(double a, double b);
/*
Undefined symbols for architecture x86_64:
  "gcd(double, double)", referenced from:
      _main in 9_함수7-7ac044.o
ld: symbol(s) not found for architecture x86_64
*/

// 2) C++11 - Delete Function
//  => 함수 호출 금지 문법
double gcd(double a, double b) = delete;
/*
9_함수7.cpp:35:11: error: call to deleted function 'gcd'
  cout << gcd(25.12, 180.10) << endl;
          ^~~
*/

int main()
{
  cout << gcd(15, 12) << endl;
  cout << gcd(25, 180) << endl;

  // cout << gcd(25.12, 180.10) << endl;
}