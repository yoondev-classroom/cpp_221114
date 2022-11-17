// 28_상속7.cpp
#include <iostream>
using namespace std;

// 추상적인 개념으로 사용하겠다.
class Animal
{
  // private 생성자: 외부 생성도 불가능하고, 자식 클래스도 접근이 불가능합니다.

  // protected 생성자 의도
  //  => Animal 객체(부모 객체)는 생성할 수 없지만,
  //     Animal 자식 객체는 생성할 수 있도록 하겠습니다.
protected:
  Animal() {}
};

class Dog : public Animal
{
public:
  // Dog() : Animal() {}
};

int main()
{
  // Animal a;
  Dog d;
}