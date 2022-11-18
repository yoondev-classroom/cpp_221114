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
  friend Point operator+(const Point &lhs, int a);
};

Point operator+(const Point &lhs, const Point &rhs)
{
  return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

// 연산자 오버로딩
//  : 객체를 대상으로 연산자를 사용할 경우, 약속된 이름의 멤버 함수 또는 일반 함수가
//    호출됩니다.

// 1. 연산자 우선순위는 변경되지 않습니다.
// 2. 피연산자의 개수도 변경되지 않습니다.
// 3. 새로운 연산자도 제공할 수 없습니다.
// 4. 연산자 오버로딩이 불가능한 연산자도 있습니다.
//  ::(범위 연산자) / .(접근 연산자) / .*(멤버 함수 포인터 접근 연산자)
//  ?:(3항 연산자)
// 5. 반드시 피연산자가 사용자 정의 타입이 있어야 합니다.
//   int operator+(int a, int b) {} => 제공 불가능합니다.
// Point operator+(const Point& lhs, int a) => 제공 가능합니다.
Point operator+(const Point &lhs, int a)
{
  return Point(lhs.x + a, lhs.y + a);
}
// 6. 반드시 멤버 함수를 통해서만 제공되어야 하는 연산자도 있습니다.
// => 클래스의 제작자만 제공할 수 있는 연산자 재정의 함수가 있습니다.
//   1) 대입 연산자:       =
//   2) 호출 연산자:       ()
//   3) 임의 접근 연산자:   []
//   4) 객체 포인터 연산자:  ->
//   5) 포인터 참조 연산자:  *

int main()
{
  Point p1(10, 20);
  Point p2(30, 40);

  Point p3 = p1 + 10;
  p3.Print();

  Point result = p1 + p2;
  result.Print();

  // 멤버 함수: p1.operator+(p2)
  // 일반 함수: operator+(p1, p2);
}