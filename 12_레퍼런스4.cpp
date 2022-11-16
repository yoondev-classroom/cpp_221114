// 12_레퍼런스4.cpp
#include <iostream>
using namespace std;

// C++ 레퍼런스
// 1. lvalue reference
//  => lvalue만 참조 가능합니다.

// 2. const lvalue reference
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

// > lvalue와 rvalue
// 1. lvalue는 대입시에 왼쪽 또는 오른쪽에 오는 식이고,
//    rvalue는 대입시에 오른쪽에만 오는 식입니다.
// 2. lvalue는 어떤 메모리의 위치를 가리키는데,
//    &연산자를 통해 그 위치를 참조할 수 있습니다.
//    rvalue는 lvalue가 아닌 값 입니다.
// 3. rvalue 참조로 정의한 것은 왼쪽값 또는 오른쪽값이 될 수 있습니다.
//    이를 판단하는 기준은 이름이 있다면 lvalue, 이름이 없다면 rvalue 입니다.

// Rvalue: 수정이 불가능합니다.
// Rvalue Reference는 lvalue입니다.

int main()
{
  int a = 10;
  int b = 20;
  const int c = 42;

  int &&rr = 10; // rr: 10이라는 임시 메모리 참조
  cout << rr << endl;

  rr = 20; // 임시 메모리의 값을 20으로 바꾼겁니다.
  cout << &rr << endl;

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

// a,r [10]

// 임시 객체 => 표현식을 벗어나면, 사라집니다.
//         => 참조를 통해 참조가 유효할 때까지 수명 연장할 수 있습니다.
int main()
{
  int a = 10;
  int &r = a;
  // r이 라는 이름을 통해 a 메모리를 접근할 수 있습니다.

  const int &cr = 100;
  // cr = 42; /* Error */
  cout << &cr << endl;

  int &&rr = 100;
  rr = 42; /* OK */
  cout << &rr << endl;
}