// 25_static2.cpp
#include <iostream>
using namespace std;

class Car
{
  static int count;
  int age;

public:
  Car() { ++count; }
  ~Car() { --count; }

  // 멤버 함수
  // - 객체를 생성해야지만 호출이 가능 합니다.

  //     멤버 함수 -> int Car::GetCount(Car* this)
  // 정적 멤버 함수 -> int Car::GetCount()

  // 정적 멤버 함수
  //  : 전역 함수와 동일한데, 클래스의 접근 제어를 할 수 있습니다.
  static int GetCount()
  {
    // this가 없기 때문에, 멤버 데이터 또는 멤버 함수 호출이 불가능합니다.

    // cout << age << endl; /* 오류 */
    //       this->age

    // this->foo();  /* 오류 */

    return count;
  }

  void foo() {}

  // friend int GetCount();
};

// 전역 함수
// int GetCount()
// {
//   return Car::count;
// }

int Car::count;

int main()
{
  // 정적 멤버 함수를 사용하는 방법 2가지
  // 1. 클래스 이름
  cout << Car::GetCount() << endl;

  Car c;
  // 2. 객체를 통해서도 호출이 가능합니다.
  cout << c.GetCount() << endl;
  //     멤버 함수: Car::GetCount(&c)
  // 정적 멤버 함수: Car::GetCount()
  //   => this가 전달되지 않습니다.
}