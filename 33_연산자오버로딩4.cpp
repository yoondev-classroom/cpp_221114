// 33_연산자오버로딩4.cpp
#include <iostream>
using namespace std;

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
