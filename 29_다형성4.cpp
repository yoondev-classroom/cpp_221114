// 29_다형성4.cpp
#include <iostream>
using namespace std;

// 1. 부모가 제공하는 함수를 자식이 동일한 함수를 재정의할 수 있습니다.
//  => 함수 오버라이딩(Overriding)
#if 1
class Animal
{
public:
  virtual void Go() const { cout << "Animal Go" << endl; }
};

class Dog : public Animal
{
public:
  virtual void Go() const { cout << "Dog Go" << endl; }
};

// 함수 바인딩(Binding): 어떤 함수를 호출할지 결정하는 것
//  :   Animal *p = &d;
//      p->Go();

// 1) 정적 바인딩(static binding)
//  => 어떤 함수를 호출할지 컴파일 타임에 결정합니다.
//     [Animal] *p = &d;
//     p->Go();
//     p의 타입을 기반으로 함수를 호출합니다.
//     - Animal::Go()
//
// => 정적 바인딩은 인라인 최적화가 가능합니다.

// 2) 동적 바인딩(dynamic binding)
//  => 어떤 함수를 호출할지 런타임에 결정합니다.
//     실행 시간에 p의 값의 타입을 조사해서, 함수를 호출합니다.
//     Animal *p = [&d];
//     p->Go()
//    - Dog::Go()

// - virtual: 멤버 함수의 호출 바인딩을 정적 바인딩에서 동적 바인딩으로
//           변경합니다.

#if 1
int main()
{
  Animal a;
  Dog d;

  Animal *p = &d;
  p->Go();

  p = &a;
  p->Go();
}
#endif

#if 0
int main()
{
  Animal a;
  a.Go();

  Dog d;
  d.Go();
}
#endif
#endif

#if 0
class Animal
{
public:
  virtual void Print() { cout << "Animal" << endl; }
};

class Dog : public Animal
{
  int a = 10;

public:
  virtual void Print() { cout << "Dog: " << a << endl; }
};

class Cat : public Animal
{
  int b = 100;

public:
  virtual void Print() { cout << "Cat: " << b << endl; }
};

#include <vector>

int main()
{
  vector<Animal *> v;
  v.push_back(new Dog);
  v.push_back(new Dog);
  v.push_back(new Cat);
  v.push_back(new Cat);

  for (auto e : v)
  {
    e->Print();
  }
}
#endif