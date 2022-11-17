// 26_상수멤버함수2.cpp
#include <iostream>
using namespace std;

class Point
{
  int x;
  int y;

public:
  Point(int a, int b)
      : x(a), y(b) {}

  void Print() const { cout << x << ", " << y << endl; }

  void Set(int a, int b)
  {
    x = a;
    y = b;
  }
};

class Rect
{
  Point leftTop;

public:
  Rect(int x, int y)
      : leftTop(x, y) {}

  // 반환 타입이 const& 인 이유를 이해해야 합니다.
  const Point &GetLeftTop() const
  {
    // leftTop: const Point

    return leftTop;
  }
};

int main()
{
}
