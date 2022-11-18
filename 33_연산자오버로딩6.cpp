// 33_연산자오버로딩6.cpp
#include <iostream>
using namespace std;

class Integer
{
  int value;

public:
  Integer(int n = 0)
      : value(n) {}

  Integer &operator++()
  {
    ++value;
    return *this;
  }

  friend ostream &operator<<(ostream &os, const Integer &n)
  {
    return os << n.value;
  }
};

int main()
{
  int n1 = 0;
  ++ ++n1;

  cout << n1 << endl;

  Integer n2;
  ++ ++n2;
  // n2.operator++().operator++().operator++()

  cout << n2 << endl;
  // 일반함수: ostream& operator<<(ostream& os, const Integer& n)
}