// 34_대입연산자.cpp
#include <iostream>
using namespace std;

class Point
{
  int x;
  int y;

public:
  Point(int a, int b) : x(a), y(b) {}

  friend ostream &operator<<(ostream &os, const Point &pt)
  {
    return os << pt.x << ", " << pt.y;
  }

  Point(const Point &rhs)
      : x(rhs.x), y(rhs.y) {}

  // 대입 연산자
  // => 연쇄 호출이 가능합니다.
  //    자기 자신의 참조를 반환해야 합니다.
  Point &operator=(const Point &rhs)
  {
    x = rhs.x;
    y = rhs.y;

    return *this;
  }
};

// 1. 사용자가 생성자를 1개도 제공하지 않으면, 컴파일러는 아무일도 수행하지 않는
//    기본 생성자를 제공합니다.
// 2. 사용자가 복사 생성자를 제공하지 않으면, 컴파일러는 멤버 복사를 수행하는
//    복사 생성자를 제공합니다.
// 3. 사용자가 대입 연산자를 제공하지 않으면, 컴파일러는 멤버 복사를 수행하는
//    대입 연산자를 제공합니다.

// => 복사 생성자와 대입 연산자는 반드시 함께 작성되어야 합니다.

int main()
{
  // int a, b, c;
  // a = b = c = 10;

  Point p1(10, 20);
  Point p2 = p1; /* 복사 생성자 */

  Point p3(100, 200);

  p3 = p1; /* 대입 연산자 */

  cout << p1 << endl;
  cout << p3 << endl;
}
