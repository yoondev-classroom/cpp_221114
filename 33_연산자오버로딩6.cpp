// 33_연산자오버로딩6.cpp
#include <iostream>
using namespace std;

class Integer
{
  int value;

public:
  inline Integer(int n = 0)
      : value(n) {}

  // ++n
  inline Integer &operator++()
  {
    ++value;
    return *this;
  }

  // n++
  // 1. 객체를 값으로 반환합니다. => 임시 객체 복사
  // 2. 현재 상태를 복사하는 복사 생성 비용
  inline Integer operator++(int)
  {
    Integer temp(*this); // 현재 상태를 복사합니다.
    ++value;

    return temp;
  }

  friend ostream &operator<<(ostream &os, const Integer &n)
  {
    return os << n.value;
  }
};

int main()
{
  int n = 0;
  ++n;
  n++;
  /*
        mov     DWORD PTR n$[rsp], 0

        mov     eax, DWORD PTR n$[rsp]
        inc     eax

        mov     DWORD PTR n$[rsp], eax
        mov     eax, DWORD PTR n$[rsp]
        inc     eax

        mov     DWORD PTR n$[rsp], eax
  */

  Integer n2 = 0; // Integer::Integer()
  ++n2;           // operator++()
  n2++;           // operator++(int)
  /*
        mov     DWORD PTR n2$[rsp], 0
        mov     eax, DWORD PTR n2$[rsp]
        inc     eax

        mov     DWORD PTR n2$[rsp], eax
        mov     eax, DWORD PTR n2$[rsp]
        mov     DWORD PTR temp$1[rsp], eax
        mov     eax, DWORD PTR n2$[rsp]
        inc     eax
        mov     DWORD PTR n2$[rsp], eax
        mov     eax, DWORD PTR temp$1[rsp]
        mov     DWORD PTR $T2[rsp], eax

  */
}

#if 0
int main()
{
  int n1 = 0;
  ++ ++n1;       // 자기 자신 참조
  int r1 = n1++; // 증가되기 이전 값

  cout << n1 << ", " << r1 << endl;

  // ++n;
  for (int i = 0; i < 10; i++)
  {
  } // C

  // n++;
  for (int i = 0; i < 10; ++i)
  {
  } // C++

  Integer n2;
  ++ ++n2;
  // n2.operator++().operator++().operator++()

  Integer r2 = n2++;
  // n2.operator++(int)

  cout << n2 << ", " << r2 << endl;
  // 일반함수: ostream& operator<<(ostream& os, const Integer& n)
}
#endif

// C++
//    스콧 마이어스
//  - Effective C++(C++98/03), 곽용재
//  - Effective Modern C++(C++11/14), 류광