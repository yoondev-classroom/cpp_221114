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

  // C++은 상수 멤버 함수와 일반 멤버 함수를 동시에 제공할 수 있습니다.
  Point &GetLeftTop()
  {
    return leftTop;
  }
};

int main()
{
  Rect rect(10, 20);
  Point &p = rect.GetLeftTop();

  p.Set(100, 200);
  p.Print();
}
