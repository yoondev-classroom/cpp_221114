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

#if 0
void foo(const int &r)
{
  cout << "const lvalue" << endl;
}

void foo(int &&rr)
{
  cout << "rvalue" << endl;
}

void foo(int &r)
{
  cout << "lvalue" << endl;
}

// Rvalue: 수정이 불가능합니다.

int main()
{
  int a = 10;
  int b = 20;
  const int c = 42;

  int &&rr = 10; // rr ---> 10
  cout << rr << endl;

  rr = 20; // 바뀌는 것이 아닙니다. // rr ---> 20
  cout << rr << endl;

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
#endif

#if 0
int main()
{
  int a = 10;
  int b = 20;

  int &r = a;
  r = 100;
  cout << a << endl;
  cout << b << endl;

  r = b; // a = 20;
  r = 50;

  cout << a << endl;
  cout << b << endl;
}
#endif

#if 0
int main()
{
  int &&r = 10; // r --> 10
  r = 20;       // 소유권 이동 r --> 20

  cout << r << endl;
}
#endif

// Rvalue reference
// 1. 소유권 이전 => move
// 2. 완벽한 전달 => perfect forwarding
