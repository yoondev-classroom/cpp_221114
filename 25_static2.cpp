// 25_static2.cpp
#include <iostream>
using namespace std;

class Car
{
  static int count;

public:
  Car() { ++count; }
  ~Car() { --count; }

  // 멤버 함수
  // - 객체를 생성해야지만 호출이 가능 합니다.

  // int Car::GetCount(Car* this)
  // 멤버 함수
  // int GetCount()

  // 정적 멤버 함수
  //  : 전역 함수와 동일한데, 클래스의 접근 제어를 할 수 있습니다.
  static int GetCount()
  {
    return count;
  }

  //

  // friend int GetCount();
};

// 전역 함수
// int GetCount()
// {
//   return Car::count;
// }

int Car::count;

// Car c;

int main()
{
  cout << Car::GetCount() << endl;

  // cout << c.GetCount() << endl;
  //     Car::GetCount(&c)
}