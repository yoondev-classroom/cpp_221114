// 22_복사생성자.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 1개도 제공하지 않으면,
//   컴파일러는 아무일도 수행하지 않는 기본 생성자를 제공합니다.

// 2. 사용자가 자신과 동일한 타입을 인자로 받는 생성자(복사 생성자)를 제공하지 않으면
//   컴파일러는 자동으로 멤버 데이터를 복사하는 복사 생성자를 만들어줍니다.

// 3. 사용자가 복사 생성자만 제공하면, 기본 생성자는 제공되지 않습니다.
//    복사 생성자도 생성자이기 때문입니다.

class Point
{
  int x;
  int y;

public:
  Point(int a, int b) : x(a), y(b) {}

  // 컴파일러가 만들어주는 복사 생성자 형태
  Point(const Point &other)
      : x(other.x), y(other.y)
  {
    cout << "Point(const Point&)" << endl;
  }

  void Print() { cout << x << ", " << y << endl; }
};

class Sample1
{
};
// 1) 아무일도 하지 않는 기본 생성자
// 2) 멤버를 복사하는 복사 생성자

class Sample2
{
public:
  Sample2(const Sample2 &) {}
};
// 3) 컴파일러는 기본 생성자를 만들어 주지 않습니다.

int main()
{
  // Point pt; => Error!
  Point pt(10, 20);
  pt.Print();

  // Point pt2 = pt;
  Point pt2(pt); // Point::Point(pt)

  pt2.Print();
}