// 18_생성자.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 1개도 제공하지 않으면,
//    컴파일러가 자동으로 "아무일도 수행하지 않는 인자 없는 생성자"를 만들어줍니다.
//    => 기본 생성자(Default Constructor)

// 2. 사용자가 생성자를 1개라도 제공하면,
//   컴파일러는 기본 생성자를 제공하지 않습니다.

class Point
{
  int x;
  int y;

public:
  // 컴파일러가 만드는 생성자 형태
  // Point() {}

#if 0
  Point()
  {
    cout << "Point()" << endl;
    x = 0;
    y = 0;
  }
#endif
  Point(int a, int b)
  {
    cout << "Point(int, int)" << endl;
    x = a;
    y = b;
  }

  void Print()
  {
    cout << x << ", " << y << endl;
  }
};

int main()
{
  // Point p1; /* Compile Error */

  Point p1(10, 20);

  p1.Print();

  return 0;
}