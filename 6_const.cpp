// 6_const.cpp
#include <iostream>
using namespace std;

// 1. C의 const와 C++의 const는 다릅니다.
//  => C의 const는 상수 표현식이 아닙니다.
//    - 배열의 크기를 지정하는데 사용할 수 없습니다.

// 2. C++ const
//  1) 반드시 초기화해야 합니다.
//  2) const
//    - 컴파일 타임 상수
//      => 컴파일 타임에 상수의 값이 결정된다면,
//         컴파일러는 변수에 대한 접근을 메모리를 통해 수행하지 않습니다.

//    - 런타임 상수
//     => 컴파일 타임에 상수의 값이 결정될 수 없다면,
//        런타임에 값을 변경할 수 없는 변수입니다.
//        런타임 상수에 대한 접근은 메모리로부터 수행됩니다.

/// 3) C++11, constexpr
//     => 컴파일 타임 상수에만 지정할 수 있습니다.

int main()
{
  constexpr int c = 100;

  // int n = 20;
  // constexpr int c = n;
  // const int c = n;

  int *p = (int *)&c;
  *p = 42;

  cout << *p << endl;
  cout << c << endl;
}
