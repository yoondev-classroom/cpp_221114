// 9_함수6.cpp

#include <iostream>
using namespace std;

#if 0
inline int square(int x) { return x * x; }
inline double square(double x) { return x * x; }
inline long long square(long long x) { return x * x; }
#endif
// > 위의 함수는 함수의 인자와 반환 타입만 다르고, 구현(알고리즘)은 동일합니다.
//   C++은 함수의 타입이 다르고 구현이 동일한 경우, 코드를 컴파일러가 자동으로 생성하는
//   문법이 제공됩니다.
//   => 템플릿(Template) / Generic(Java, C#, ...)

template <typename TYPE> // 타입 파라미터
TYPE square(TYPE x)
{
  return x * x;
}
// 함수 템플릿
//  1. 인자의 타입을 통해 TYPE을 결정하고, 컴파일 타임에 함수를 생성합니다.
//  2. 컴파일 타임에 코드를 생성하기 때문에, 컴파일 시간이 증가합니다.
//  3. 인자로 전달된 타입에 따라 코드가 생성되기 때문에,
//     다양한 타입을 전달할 경우, 코드 메모리 사용량이 증가할 수 있습니다.
//   => inline 최적화와 사용될 경우, 코드 메모리 사용량도 최적화될 수 있습니다.

#if 1
int main()
{
  cout << square(10) << endl;    // TYPE -> int
  cout << square(3.14) << endl;  // TYPE -> double
  cout << square(100LL) << endl; // TYPE -> long long
  // 암묵적으로 타입을 추론합니다.

  cout << square<long long>(1000L) << endl; // TYPE -> long long
  // 명시적으로 타입을 지정합니다.
}
#endif

// STL(Standard Template Library)
// => C++ 표준 라이브러리
//   많은 요소들이 템플릿 기반으로 제공됩니다.

template <typename TYPE1, typename TYPE2>
void foo(TYPE1 a, TYPE2 b)
{
}

int main()
{
  foo(10, 'A'); // foo<int, char>(10, 'A')
}