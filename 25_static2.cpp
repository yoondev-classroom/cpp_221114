// 25_static2.cpp
#include <iostream>
using namespace std;

// * 멤버 데이터, 멤버 함수
// 1. this
//   : 객체를 생성해야지만 사용할 수 있습니다.
// 2. 멤버 함수의 호출을 통해 this가 암묵적으로 전달됩니다.
//    a) 멤버 함수 안에서 멤버 데이터에 접근과 멤버 함수 호출이 가능합니다.
//    b) 멤버 함수 안에서 정적 멤버 데이터와 정적 멤버 함수를 호출할 수 있습니다.

// 3. 객체의 상태와 행위를 모델링합니다.

// * 정적 멤버 데이터 / 정적 멤버 함수
// 1. 전역 변수와 전역 함수와 동일한데, 클래스의 접근 지정자를 사용할 수 있습니다.
// 2. 사용하는 방법 2가지
//   1) 클래스
//   클래스이름::X();
//   클래스이름::count = 0;
//   2) 객체
//   객체.X();
//   객체.count = 0;

// 3. this가 암묵적으로 전달되지 않기 때문에, 객체를 생성하지 않아도 접근할 수 있습니다.
// 4. this가 전달되지 않기 때문에, 정적 멤버 함수 안에서 멤버 데이터와 멤버 함수에 접근할 수
//    없습니다.

// 5. 클래스의 상태와 행위를 모델링합니다.
//   "클래스 변수 / 클래스 메소드"

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