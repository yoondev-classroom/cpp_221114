// 6_const.cpp
#include <iostream>
using namespace std;

// 1. C의 const와 C++의 const는 다릅니다.
//  => C의 const는 상수 표현식이 아닙니다.
//    - 배열의 크기를 지정하는데 사용할 수 없습니다.
//    - 런타임 상수로만 취급됩니다.
//  => C++ const 전역 변수: internal linkage
//        const int global = 100; => static
//     C const 전역 변수: external linkage
//        const int global = 100; => extern

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

// 3. const를 사용할 수 있다면,
//    반드시 적용해야 합니다. => "불변성"
//   - 값이 변경되는 경로를 쉽게 추적할 수 있습니다.
//   - 값을 안전하게 공유할 수 있습니다.
//   - 병렬성을 갖는 프로그램에서 안전하게 공유할 수 있습니다.
//   - 대상체를 읽을 때, 메모리로부터 읽는 것이 아니라,
//     바로 값으로 읽어서 처리할 수 있습니다. => 컴파일 타임 상수

struct Point
{
  int x;
  int y;
};

int main()
{
  constexpr struct Point pt1 = {10, 20};
  // 초기화 이후에 값이 변경될 수 없습니다. => 불변성
  cout << pt1.x << ", " << pt1.y << endl;

  // constexpr int c = 100;

  int n = 20;
  const int c = n;
  // constexpr int c = n; // Compile Error
  /*
  constexpr variable 'c' must be initialized by a constant expression

  */

  int *p = (int *)&c;
  // *p = 42; /* 미정의 동작 */

  cout << *p << endl;
  cout << c << endl;
}
