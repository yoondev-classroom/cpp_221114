// 29_다형성.cpp
#include <iostream>
using namespace std;

class Animal
{
};

class Dog : public Animal
{
};

// 1. Upcasting: 부모 클래스의 포인터/참조를 통해 자식 객체의 주소를 참조할 수 있습니다.
//   Animal
//     |
//    Dog

// 2. Dog is a Animal
//   : 자식 클래스는 부모 클래스는 is-a 관계가 성립합니다.

int main()
{
  Animal a;
  Animal *p = &a;

  Dog d;
  Dog *p2 = &d;

  // 자식의 객체의 주소를 부모 포인터 타입을 통해 참조할 수 있습니다.
  Animal *p3 = &d;

  // 자식 객체를 부모 타입의 참조 타입을 통해 참조할 수 있습니다.
  Animal &ra = d;

  // 부모 타입의 주소 또는 부모 타입의 객체를 참조하는 것은 암묵적으로 허용되지 않습니다.
  // Dog *p4 = &a;
  // Dog &rd = a;
}