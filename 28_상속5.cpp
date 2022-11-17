// 28_상속5.cpp
#include <iostream>
using namespace std;

class Base
{
public:
  Base(int n) {}
  Base(int a, int b) {}
  Base(int a, int b, int c) {}
};

class Derived : public Base
{
public:
  // 컴파일러가 만들어주는 생성자
  // Derived(): Base() {}

  Derived() : Base(42) {}
};

// 에러: 부모의 기본 생성자가 없는 경우,
//      컴파일러가 자동으로 생성하는 기본 생성자에서는
//      부모의 기본 생성자를 호출하고자 하기 때문입니다.

// 해결 방법
//  => 부모가 기본 생성자를 제공하지 않는 경우, 반드시 초기화리스트를 통해 부모의 생성자를
//     명시적으로 호출해야 합니다.

int main()
{
  Derived d;
}