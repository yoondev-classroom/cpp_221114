// 20_this.cpp
#include <iostream>
using namespace std;

#if 0
struct Point
{
  int x;
  int y;
};

void Set(Point *pt, int x, int y)
{
  pt->x = x;
  pt->y = y;
}

int main()
{
  Point pt = {10, 20};

  Set(&pt, 30, 40);

  cout << pt.x << endl;
  cout << pt.y << endl;
}
#endif

struct Point
{
  int x;
  int y;

  // this는 멤버 함수 내부에서 사용할 수 있는 전달 받은 객체의 주소를
  // 의미합니다.
  void Set(int ax, int ay)
  {
    this->x = x;
    this->y = y;
    // x = ax;
    // y = ay;
  }
};

int main()
{
  Point pt1, pt2;

  pt1.Set(10, 20);
  pt2.Set(20, 30);
}

#if 0

int main()
{
  Point pt = {10, 20};

  pt.Set(30, 40);

  cout << pt.x << endl;
  cout << pt.y << endl;
}
#endif