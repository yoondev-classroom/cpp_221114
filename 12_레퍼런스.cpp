// 12_레퍼런스.cpp
//  : 중요합니다.

#include <iostream>
using namespace std;

#if 0
int main()
{
  int n = 100;

  int *p = &n;

  *p = 42;

  cout << *p << endl;
  cout << n << endl;
}
#endif

// C++ 레퍼런스 타입이 존재합니다.
//  => 기존 메모리에 새로운 이름(별명)을 부여합니다.

int main()
{
  int n = 100;

  int &r = n;

  r = 42;

  cout << r << endl;
  cout << n << endl;
}