// 29_다형성7.cpp

#include <iostream>
using namespace std;

// 가상 소멸자
//  : 부모 클래스의 소멸자는 반드시 가상이어야 합니다.
//  => 소멸자가 가상 소멸자가 아닌 클래스는 상속하면 안됩니다.
class Animal
{
public:
  Animal() { cout << "Animal()" << endl; }
  virtual ~Animal() { cout << "~Animal()" << endl; }
};

class Dog : public Animal
{
public:
  Dog() { cout << "Dog()" << endl; }

  // 부모의 소멸자가 가상이면, 자식의 소멸자도 가상입니다.
  ~Dog() override { cout << "~Dog()" << endl; }
  // 부모의 소멸자가 가상인지 확인할 수 있습니다.
};

// 문제점: 자식의 소멸자가 호출되지 않아서, 메모리 누수의 위험성이 있습니다.
//  원인: 소멸자가 정적 바인딩 기반으로 호출되기 때문입니다.
//    p의 타입이 부모 타입일 경우, 자식의 소멸자가 제대로 호출되지 않습니다.

int main()
{
  // Dog d;
  //  Dog::Dog()
  //  Dog::~Dog()

  Animal *p = new Dog;
  // Dog::Dog()

  delete p;
  // 가상 소멸자가 아닌 경우, Animal::~Animal()
  // 가상 소멸자인 경우는 실행 시간에 p의 객체의 실제 타입을 조사해서
  // 소멸자를 호출합니다. => Dog::~Dog()
}