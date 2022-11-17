// 21_초기화리스트.cpp
#include <iostream>
using namespace std;

// 1. 초기화와 대입의 차이를 알아야 합니다.
#if 0
int main()
{
  int a = 10; // 초기화

  int b;
  b = 10; // 대입

  // 초기화가 반드시 필요합니다.
  // const int c;
  // int &r;
}
#endif

// 2. C++ 에서는 초기화가 반드시 필요한 경우가 있습니다.
//  1) const
//  2) reference

// 3. 초기화 리스트의 문법을 통해 생성자에서 멤버에 대한 초기화가 가능합니다.

// 4. 초기화 리스트를 사용해야 하는 경우
//    1) const 멤버
//    2) reference 멤버
//    3) 멤버 클래스가 기본 생성자를 제공하지 않을 경우
//    4) 부모 클래스가 기본 생성자를 제공하지 않을 경우

#if 0
class Sample
{
  const int a;
  int &b;

public:
  Sample(int aa, int &ab)
      : a(aa), b(ab)
  {
    // 초기화가 아니라 대입입니다.
    // a = aa;
    // b = ab;
  }
};

int main()
{
}
#endif

// * 멤버의 초기화 순서는 초기화 리스트의 순서에 의해서 결정되지 않습니다.
//  => 멤버가 선언된 순서로 초기화됩니다.

// * 멤버의 선언 순서와 초기화 리스트의 초기화 순서를 동일하게 작성해야 합니다.

class Point
{
  // int x;

  int x;
  int y;

public:
  Point(int n)
      : x(n), y(x)
  // : y(x), x(n)
  {
  }

  void Print()
  {
    cout << x << ", " << y << endl;
  }
};

int main()
{
  // Point pt(100);
  Point pt(100);
  pt.Print();
}