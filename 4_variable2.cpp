// 4_variable2.cpp

#include <iostream>
using namespace std;
// 중요합니다.

struct Point
{
  int x;
  int y;
};

#if 0
int main()
{
  // Copy Initialization(복사 초기화) => C/C++
  int n1 = 10;
  int x1[3] = {1, 2, 3};
  Point p1 = {10, 20};

  // Direct Initialization(직접 초기화) => C++
  int n2(10);
  int x2[3]{1, 2, 3};
  Point p2{10, 20};
}
#endif

#if 0
// C++11 - Uniform Initialization(일관된 초기화)
int main()
{
  // Copy Initialization(복사 초기화)
  int n1 = {10};
  int x1[3] = {1, 2, 3};
  Point p1 = {10, 20};

  // Direct Initialization(직접 초기화)
  int n2{10};
  int x2[3]{1, 2, 3};
  Point p2{10, 20};
}
#endif

// C              => Go
// C++            => Rust >>>  D, Carbon
// Java           => Kotlin, Scala
// Objective-C    => Swift
// => 현대적인 언어는 정수 타입 간의 암묵적인 변환이 허용되지 않습니다.
//   : 암묵적인 타입의 변환은 위험하다.

int main()
{
  double d = 3.14;

  int n1 = d;
  int n2(d);

  // int n3 = {d}; // Compile error!
  // int n4{d};    // Compile error!

  // - Uniform Initialization을 사용하면 컴파일 타임에 암묵적인 변환을
  //   금지할 수 있습니다.
  // => 명시적인 캐스팅이 필요합니다.
  // => Preventing Narrow 기능을 제공합니다.

  int n3 = {(int)d};
  int n4{(int)d};

  cout << n1 << endl;
  cout << n2 << endl;
  cout << n3 << endl;
  cout << n4 << endl;

  long long l = INT_MAX + 1LL;
  int x1 = l;
  int x2(l);
  cout << x1 << endl;
  cout << x2 << endl;

  int x3 = {(int)l};
  int x4{(int)l};

  long long l2{x4}; // Promotion - OK!
}
