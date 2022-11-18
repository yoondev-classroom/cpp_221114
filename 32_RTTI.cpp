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
//  => Downcasting, 명시적인 캐스팅이 필요합니다.

// 3. RTTI(Run Time Type Information)
//  => type_info 구조체
//   : 같은 타입이면 type_info가 동일합니다.
//  => type_info 구조체를 얻는 방법
//     typeid(Dog): 클래스
//      typeid(*p): 객체

// 4. RTTI를 직접 사용하는 것보다 더 좋은 방법
//  => dynamic_cast를 이용하면 됩니다.
//  => 반드시 가상함수 테이블이 존재해야 합니다.

int main()
{
  Animal a;
  Dog d;

  // Animal *p = &d;
  Animal *p = &d;

#if 0
  // p가 Dog 타입으로의 캐스팅이 필요합니다.
  if (typeid(*p) == typeid(Dog))
  {
    Dog *pDog = static_cast<Dog *>(p);
    cout << pDog->GetColor() << endl;
  }
#endif

  Dog *pDog = dynamic_cast<Dog *>(p);
  // 실행 시간에 p의 타입을 조사합니다.
  // p의 타입이 캐스팅이 불가능하면, nullptr을 반환합니다.ㄴ
  if (pDog)
  {
    cout << pDog->GetColor() << endl;
  }
}