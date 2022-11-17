// 29_다형성6.cpp
#include <iostream>
using namespace std;

class Animal
{
public:
  virtual void Go() { cout << "Animal Go" << endl; }
};

class Cat : public Animal
{
public:
  void Go() override {}
};

//  C++11에서 오버라이딩 금지를 위한 키워드가 도입되었습니다.
//   => final
class Dog : public Animal
{
public:
  // Dog의 자식 클래스는 더 이상 Go를 오버라이딩 금지하고 싶다.
  void Go() override final { cout << "Dog Go" << endl; }
};

class Pomeranian : public Dog
{
public:
  // void Go() override { cout << "Pomeranian Go" << endl; }
};

int main()
{
  Animal *p = new Pomeranian;
  p->Go();
}