// 9_함수8.cpp
#include <iostream>
using namespace std;

// C++11
// : 함수를 만드는 새로운 문법이 도입되었습니다.
//   "Trailing Return Type"

#if 0
// 전통적인 방식
int add1(int a, int b) { return a + b; }

// Trailing Return Type
auto add2(int a, int b) -> int { return a + b; }

int main()
{
  cout << add1(10, 20) << endl;

  cout << add2(10, 20) << endl;
}
#endif

// 1) 반환 타입의 가독성
//    반환 타입을 컴파일러가 추론합니다.
#if 0
int (*foo1())[3]
{
  static int x[3] = {10, 20, 30};
  return &x; // int (*)[3]
}

// auto foo2() -> int (*)[3]
auto foo2()
{
  static int x[3] = {10, 20, 30};
  return &x;
}

// 아래 처럼 작성하면, 컴파일러가 return 타입을 추론합니다.
// 반환 타입을 명시하지 않아도 됩니다.
// auto add(int a, int b) -> int
auto add(int a, int b)
{
  return a + b;
}

int main()
{
  cout << add(10, 20) << endl;
}
#endif

// 2) decltype를 이용해, 반환 타입을 파라미터 타입을 통해
//    결정할 때

// 아래의 코드는 컴파일되지 않습니다.
//   문제점: 파라미터 기반으로 반환타입을 decltype을 통해 결정할 때
//         파라미터 정보가 반환 타입 뒤에 있습니다.
#if 0
decltype(a + b) add(int a, int b)
{
  return a + b;
}
#endif

auto add(int a, int b) -> decltype(a + b)
{
  return a + b;
}

int main()
{
}