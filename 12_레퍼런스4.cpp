// 12_레퍼런스4.cpp
#include <iostream>
using namespace std;

// C++ 레퍼런스
// 1. lvalue reference
//  => lvalue만 참조 가능합니다.

// 2. const reference
//  => lvalue, rvalue, const lvalue 참조가 가능합니다.

// 3. C++11, rvalue reference
//  => rvalue만 참조 가능합니다.

#if 0
// b = a;
// a = 3;
// lvalue: 왼쪽에도 오른쪽에 둘 수 있습니다.
// rvalue: 왼쪽에 올 수 없고, 오른쪽에만 둘 수 있습니다.

void foo(int &r)
{
  cout << "lvalue ref" << endl;
}

void foo(const int &cr)
{
  // 문제점: const lvalue를 처리할 때와,
  //       rvalue를 처리할 때를 구분할 수 없습니다.

  cout << "const lvalue ref" << endl;
}

int main()
{
  // int& r; => lvalue reference
  // const int& r; => const reference

  int a = 10;
  const int c = 100;

  const int &cr1 = a;  /* OK */
  const int &cr2 = 10; /* OK */
  const int &cr3 = c;  /* OK */

  foo(a);  // lvalue
  foo(c);  // const lvalue
  foo(10); // const lvalue

  // foo(a);  /* OK */
  // foo(10); /* Compile Error */

  // int &r1 = a;  /* OK */
  // int &r2 = 10; /* Compile Error */
}
#endif

void foo(const int &r)
{
  cout << "const lvalue" << endl;
}

void foo(int &&rr)
{
  cout << "lvalue" << endl;
}

void foo(int &r)
{
  cout << "rvalue" << endl;
}

int main()
{
  int a = 10;
  const int c = 42;

  foo(a);  // lvalue
  foo(10); // rvalue
  foo(c);  // const lvalue

  // 1. lvaule reference는 lvalue만 참조 가능합니다.
  int &r1 = a; /* OK */
  // int &r2 = 10; /* Compile Error */
  // int &r3 = c;  /* Compile Error */

  // 2. rvalue reference는 rvalue만 참조 가능합니다.
  // int &&rr1 = a; /* Compile Error */
  int &&rr2 = 10; /* OK */
  // int &&rr3 = c;  /* Compile Error */

  // 3. const lvalue reference
  //   const lvalue, lvalue, rvalue
  const int &cr1 = a;  /* OK */
  const int &cr2 = 10; /* OK */
  const int &cr3 = c;  /* Ok */
}