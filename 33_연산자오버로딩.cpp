// 33_연산자오버로딩.cpp
#include <iostream>
using namespace std;

#if 0
class Point
{
  int x;
  int y;

public:
  Point(int a, int b) : x(a), y(b) {}

  // int GetX() const { return x; }
  // int GetY() const { return y; }

  void Print() const { cout << x << ", " << y << endl; }

  Point Add(const Point &rhs)
  {
    return Point(x + rhs.x, y + rhs.y);
  }

  friend Point Add(const Point &lhs, const Point &rhs);
};

Point Add(const Point &lhs, const Point &rhs)
{
  return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}




int main()
{
  Point p1(10, 20);
  Point p2(30, 40);

  // 더하는 기능을 만들고 싶습니다.
  //  - 만드는 방법 2가지
  //  1) 멤버 함수
  // Point result = p1.Add(p2); // Point::Add(&p1, p2);
  // result.Print();

  //  2) 일반 함수
  Point result = Add(p1, p2);
  result.Print();
}
#endif

class Point
{
  int x;
  int y;

public:
  Point(int a, int b) : x(a), y(b) {}

  // int GetX() const { return x; }
  // int GetY() const { return y; }

  void Print() const { cout << x << ", " << y << endl; }

// Point Add(const Point &rhs)
#if 0
  Point operator+(const Point &rhs)
  {
    return Point(x + rhs.x, y + rhs.y);
  }
#endif

  friend Point operator+(const Point &lhs, const Point &rhs);
};

Point operator+(const Point &lhs, const Point &rhs)
{
  return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

int main()
{
  Point p1(10, 20);
  Point p2(30, 40);

  Point result = p1 + p2;
  result.Print();

  // 멤버 함수: p1.operator+(p2)
  // 일반 함수: operator+(p1, p2);
}