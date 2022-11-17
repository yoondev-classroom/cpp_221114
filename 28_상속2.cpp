// 28_상속2.cpp

#include <iostream>
#include <string>
using namespace std;

#if 0
class Animal
{
};

class Dog
{
private:
  int age;
  int color;
};

class Cat
{
private:
  int age;
  int speed;
  string name;
};

int main()
{
  cout << sizeof(Dog) << endl;
  cout << sizeof(Cat) << endl;
}
#endif

//   Animal: 부모, Base,    Super
// Dog, Cat: 자식, Derived, Sub
class Animal
{
private:
  int age;
};

// C++ 상속
//  class 자식 : public 부모
//             -------
//                 ^ 접근 변경자: 부모가 제공하는 기능을 어떤 접근 지정자로 받아서
//                             사용할지 결정하는 키워드입니다. => C++만 제공되는 기능입니다.
// 상속: 'public 상속'을 의미합니다.

class Dog : public Animal
{
private:
  int color;
};

class Cat : public Animal
{
private:
  int speed;
  string name;
};

int main()
{
  cout << sizeof(Dog) << endl;
  cout << sizeof(Cat) << endl;
}