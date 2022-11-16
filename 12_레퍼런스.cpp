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

  int *p2 = NULL; // 참조하는 대상체가 존재하지 않음
}
#endif

#if 1
// C++ 레퍼런스 타입이 존재합니다.
//  => 기존 메모리에 새로운 이름(별명)을 부여합니다.
int main()
{
  int n = 100;

  // int &r = n;
  // auto r = n;    // auto -> int
  auto &r = n; // auto -> int

  r = 42;
  cout << r << endl;
  cout << n << endl;

  // int &r2; // Compile Error
  // => 레퍼런스는 반드시 초기화가 필요합니다.
  //  : 널을 대입할 수 없습니다.

  int x[3] = {10, 20, 30};
  for (auto &e : x)
  {
    e += 10;
  }

  for (auto e : x)
  {
    cout << e << endl;
  }
}
#endif