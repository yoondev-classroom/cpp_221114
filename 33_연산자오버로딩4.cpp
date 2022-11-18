// 33_연산자오버로딩4.cpp
#include <iostream>
using namespace std;

// 사용자 정의 타입을 표준 라이브러리를 통해 입출력 하는 확장이 가능합니다.

#if 0
class Point
{
  int x = 0;
  int y = 0;

public:
  friend istream &operator>>(istream &is, Point &pt);
  friend ostream &operator<<(ostream &os, const Point &pt);
};

istream &operator>>(istream &is, Point &pt)
{
  return is >> pt.x >> pt.y;
}

ostream &operator<<(ostream &os, const Point &pt)
{
  return os << pt.x << ", " << pt.y;
}
#endif

class Point
{
  int x = 0;
  int y = 0;

public:
  // friend 함수를 클래스 내부에 작성할 수 있습니다.
  friend istream &operator>>(istream &is, Point &pt)
  {
    return is >> pt.x >> pt.y;
  }

  friend ostream &operator<<(ostream &os, const Point &pt)
  {
    return os << pt.x << ", " << pt.y;
  }
};

int main()
{
  Point pt;

  cin >> pt;
  // 멤버함수: istream& cin.operator>>(Point&)
  // 일반함수: istream& operator>>(istream& is, Point& pt)

  cout << pt << endl;
  // 멤버함수: ostream& cout.operator<<(const Point&)
  // 일반함수: ostream& operator<<(ostream& os, const Point& pt)
}
