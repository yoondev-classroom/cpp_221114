// 21_초기화리스트2.cpp
#include <iostream>
using namespace std;

class Point
{
public:
  Point(int x, int y) {}
};

class Rect
{
  Point leftTop;
  Point rightBottom;

public:
  // 컴파일러가 만들어주는 기본 생성자 형태
  // Rect() : leftTop(), rightBottom() {}

  // 멤버 객체가 기본 생성자가 존재하지 않는 경우, 반드시 초기화리스트를 통해
  // 명시적으로 초기화해주어야 합니다.
  Rect(int x1, int y1, int x2, int y2)
      : leftTop(x1, y1), rightBottom(x2, y2) // !!!
  {
  }
};

int main()
{
  Rect r(10, 20, 30, 40);
}