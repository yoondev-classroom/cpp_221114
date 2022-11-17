// 26_상수멤버함수.cpp
//  => 중요합니다.

#include <iostream>
using namespace std;

class Point
{
  int x;
  int y;

public:
  Point(int a, int b)
      : x(a), y(b) {}

  void Print() const
  {
    // x -> const int
    // y -> const int

    cout << x << ", " << y << endl;
  }
};

// 1. 상수 객체 또는 상수 참조를 통해 멤버 함수를 호출할 때
//    일반 멤버 함수는 호출이 불가능합니다.
//   => 상수 멤버 함수만 호출이 가능합니다.

// 2. void Print() const
//   => 상수 멤버 함수
//    : 상수 멤버 함수는 멤버 함수 안에서 멤버 데이터를 상수 취급합니다.

// 3. 멤버 함수를 만들 때, 멤버 데이터의 값을 변경하지 않는 멤버 함수는
//    반드시 상수 멤버 함수로 만들어야 합니다.

// void foo(Point p)
void foo(const Point &p)
{
  p.Print();
}

int main()
{
  Point p1(10, 20);
  p1.Print(); /* OK */

  const Point p2(20, 30); // 상수 객체
  // p2.Print();

  Point p3(10, 30);
  const Point &r = p3;

  // r.Print();
}