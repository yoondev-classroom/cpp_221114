// 25_static.cpp
#include <iostream>
using std::cout;
using std::endl;

#if 0
// 자동차 객체가 몇개 생성되는지 관리하고 싶습니다.

// 문제점: 외부에서 누구나 접근이 가능합니다.
//       Car의 속성으로 사용되지만, Car의 접근 제어가 적용되지 않습니다.
int count;

class Car
{
  int color;
  int age;

public:
  Car() { count++; }
  ~Car() { count--; }

  int GetCount() { return count; }
};

Car car1;
Car car2;

int main()
{
  count = 100;
  cout << car1.GetCount() << endl;
  cout << car2.GetCount() << endl;
}
#endif

// 자동차 객체가 몇개 생성되는지 관리하고 싶습니다.
// int count;

// 해결 방법
//  => 정적 멤버 데이터

class Car
{
private:
  int color;
  int age;

  // static int count; // 선언
public:
  static int count; // 선언

  Car() { count++; }
  ~Car() { count--; }

  int GetCount() { return count; }
};

// 소스 파일에 작성되어야 합니다.
int Car::count = 0; // 정의

Car car1;
Car car2;
Car car[5];

int main()
{
  // 접근하는 방법
  // 1. 클래스 이름
  Car::count = 100;

  // 2. 객체를 통해서 접근 가능합니다.
  cout << car1.count << endl;

  cout << car1.GetCount() << endl;
  cout << car2.GetCount() << endl;
}