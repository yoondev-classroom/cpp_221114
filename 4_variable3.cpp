// 4_variable3.cpp
#include <iostream>
using namespace std;

#if 0
int main()
{
  int x[3] = {10, 20, 30};

  int n = x[0];
  int *p = x;
}
#endif

// auto: C++11에서 추가된 키워드입니다.
// > 우항의 표현식을 통해 컴파일 타임에 타입을 추론합니다.
//  - 기존 C의 auto 키워드를 다른 의미로 사용합니다.
//  => Type deduction

// > 타입간의 의존성을 관리하는데 유용합니다.
// 주의사항
//  1) 배열에서는 사용 안됩니다.
//  2) 반드시 초기화가 필요합니다.
//  3) 우항의 표현식과 동일한 타입이 아니라, 추론입니다.

int main()
{
  int x[3] = {10, 20, 30};

  auto n = x[0]; // auto -> int
  auto p = x;    // auto -> int*

  // auto y;

  const int c = 100; // const int
  // auto y = c;        // auto -> int
  const auto y = c;

  // y = 100; /* Compiler error */
  cout << y << endl;
}