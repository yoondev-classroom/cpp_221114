// 18_생성자2.cpp
#include <iostream>

#include <cstdlib>
using namespace std;

class Point
{
public:
  Point() { cout << "Point()" << endl; }
  Point(int x, int y) { cout << "Point(int, int)" << endl; }

  ~Point() { cout << "~Point()" << endl; }
};

// 1. malloc을 통해서 객체를 생성하면,
//    생성자가 호출되지 않습니다.

// 2. free를 통해서 객체를 해지하면,
//    소멸자가 호출되지 않습니다.

// 3. new를 통해서 객체를 생성하면, 생성자가 호출되고
//    delete를 통해서 객체를 파괴하면, 소멸자가 호출됩니다.
//     * new
//    1. 메모리 할당
//    2. 할당된 메모리를 대상으로 생성자 호출

//     * delete
//    1. 해지할 메모리를 대상으로 소멸자를 호출
//    2. 메모리 해지

#if 0
int main()
{
  // Point *p1 = static_cast<Point *>(malloc(sizeof(Point)));
  // free(p1);

  Point *p1 = new Point; // Point()
  delete p1;

  Point *p2 = new Point(10, 20); // Point(int, int)
  delete p2;

  Point *p3 = new Point{10, 20}; // Point(int, int)
  delete p3;
}
#endif

int main()
{
  // Point *p = new Point[3];

  Point *p = new Point[3]{
      {10, 20}, // Point(int, int)
      {20, 30}, // Point(int, int)
                // {}, Point()
  };

  delete[] p;
}