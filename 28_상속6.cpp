// 28_상속6.cpp
#include <iostream>
#include <string>
using namespace std;

class Cat
{
  int age_;
  int color_;
  string name_;

public:
  Cat(int age, int color, const string &name)
      : age_(age), color_(color), name_(name)
  {
  }

  int GetAge() const { return age_; }
  int GetColor() const { return color_; }
  string GetName() const { return name_; }
};

class Dog
{
  int age_;
  int speed_;
  string name_;

public:
  Dog(int age, int speed, const string &name)
      : age_(age), speed_(speed), name_(name)
  {
  }

  int GetAge() const { return age_; }
  string GetName() const { return name_; }
};

//---
// => 아래의 코드는 수정없이 동작해야 합니다.
int main()
{
  Dog d(42, 100, "Navi");
  Cat c(255, 100, "Hello");

  cout << d.GetAge() << endl;
  cout << d.GetName() << endl;

  cout << c.GetAge() << endl;
  cout << c.GetColor() << endl;
  cout << c.GetName() << endl;
}