// 29_다형성2.cpp
#include <iostream>
using namespace std;

#if 0
class Dog
{
  int age = 10;

public:
  int GetAge() const { return age; }
};

class Cat
{
  int age = 10;

public:
  int GetAge() const { return age; }
};

void PrintAge(Dog *p)
{
  cout << p->GetAge() << endl;
}

void PrintAge(Cat *p)
{
  cout << p->GetAge() << endl;
}

int main()
{
  Dog d;
  PrintAge(&d);

  Cat c;
  PrintAge(&c);
}
#endif

class Animal
{
  int age = 10;

public:
  int GetAge() const { return age; }
};

class Dog : public Animal
{
};

class Cat : public Animal
{
};

class Rabbit : public Animal
{
};

// 활용 1. 동종을 처리하는 함수를 정의할 수 있습니다.
//  - Animal의 자식 클래스는 해당 기능을 이용할 수 있습니다.
void PrintAge(Animal *p)
{
  cout << p->GetAge() << endl;
}

int main()
{
  Dog d;
  PrintAge(&d);

  Cat c;
  PrintAge(&c);

  Rabbit r;
  PrintAge(&r);
}