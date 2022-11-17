// 22_복사생성자5.cpp
#include <iostream>
using namespace std;

class Sample
{
public:
  Sample() {}
  Sample(const Sample &rhs) { cout << "Sample(const&)" << endl; }
  ~Sample() { cout << "~Sample()" << endl; }
};

// 1. g가 유지되는 메모리이기 때문에, 참조 반환이 가능합니다.
#if 0
Sample g;
Sample& foo()
{
	return g;
}
#endif

// 2. g는 지역 객체이므로, 함수가 종료되면 사라집니다.
//    사라지는 변수에 대한 참조를 반환하면 안됩니다.
#if 0
Sample foo()
{
	Sample g; /* 지역 객체 */
	return g;
}
#endif

// 해결방법: RVO(Return Value Optimization)
//  => 임시 객체를 만들면서, 반환하면 임시 객체의 생성 비용을 제거할 수 있습니다.

//  최신 컴파일러는 NRVO(Named RVO)를 지원합니다.

Sample foo()
{
  // Sample g;
  // return g;
  return Sample(); // RVO, 임시 객체 생성 문법
}

class Point
{
  int x;
  int y;

public:
  Point(int a, int b)
      : x(a), y(b)
  {
  }

  Point(const Point &rhs)
      : x(rhs.x), y(rhs.y)
  {
    cout << "복사 생성자" << endl;
  }

  void Print()
  {
    cout << x << ", " << y << endl;
  }

  friend Point Add(const Point &p1, const Point &p2);
};

// -fno-elide-constructors: RVO 최적화 끄는 옵션
Point Add(const Point &p1, const Point &p2)
{
  // 만드는 방법 1. NRVO
  Point ret(p1.x + p2.x, p1.y + p2.y);
  return ret;

  // 만드는 방법 2. 임시 객체 반환, RVO
  // return Point(p1.x + p2.x, p1.y + p2.y);
}

int main()
{
  Point p1(10, 20);
  Point p2(30, 40);

  Add(p1, p2);

  // foo();
}