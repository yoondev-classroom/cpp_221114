// 33_연산자오버로딩6.cpp
#include <iostream>
using namespace std;

class Integer
{
  int value;

public:
  Integer(int n = 0)
      : value(n) {}

  // ++n
  Integer &operator++()
  {
    ++value;
    return *this;
  }

  // n++
  // 1. 객체를 값으로 반환합니다. => 임시 객체 복사
  // 2. 현재 상태를 복사하는 복사 생성 비용
  Integer operator++(int)
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