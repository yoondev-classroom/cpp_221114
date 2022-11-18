// 30_가상함수의원리.cpp
#include <iostream>
using namespace std;

class Animal
{
  int age;

public:
  virtual void Go() { cout << "Animal Go" << endl; }
};

class Dog : public Animal
{
  int color;
  double height;

public:
};

// <가상 함수의 비용>
// 1. 가상 함수를 사용하는 모든 객체의 크기가 8바이트(가상 함수 테이블 참조 포인터)
//    늘어납니다.
// 2. 가상 함수 테이블
//    가상함수를 가진 클래스 * 가상함수의 개수

int main()
{
  Animal *p = new Dog;
  p->Go(); // (p->vftp)[0](p);

  // cout << sizeof(Animal) << endl;
  // cout << sizeof(Dog) << endl;
}