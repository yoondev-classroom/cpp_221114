// 32_RTTI.cpp
#include <iostream>
using namespace std;

class Animal
{
public:
  virtual ~Animal() {} // !!
};

class Dog : public Animal
{
  int color = 42;

public:
  int GetColor() const { return color; }
};

// 1. 자식 포인터(참조) 타입은 부모 포인터(참조) 타입으로의 암묵적인 변환이 허용됩니다.
//   => Upcasting

// 2. 부모 포인터(참조) 타입을 자식 포인터 타입으로의 암묵적인 변환은 허용되지 않습니다.
//  => 명시적인 캐스팅이 필요합니다.

// 3. RTTI(Run Time Type Information)
//  => type_info 구조체
//   : 같은 타입이면 type_info가 동일합니다.
//  => type_info 구조체를 얻는 방법
//     typeid(Dog): 클래스
//      typeid(*p): 객체

int main()
{
  Animal a;
  Dog d;

  // Animal *p = &d;
  Animal *p = &d;

  // p가 Dog 타입으로의 캐스팅이 필요합니다.
  if (typeid(*p) == typeid(Dog))
  {
    Dog *pDog = static_cast<Dog *>(p);
    cout << pDog->GetColor() << endl;
  }
}