// 28_상속3.cpp
#include <iostream>
using namespace std;

// 1. 부모의 private은 자식 클래스도 접근이 불가능합니다.

// 2. C++ 접근 지정자 3개
// 1. private: 외부 접근 불가능, friend 함수, 클래스 가능
// 2. protected: 외부 접근 불가능, 자식 클래스 접근 가능
// 3. public: 외부 접근 가능

class Animal
{
protected:
  int age = 100;
};

class Dog : public Animal
{
public:
  void PrintAge() const
  {
    cout << age << endl; /* OK */
  }
};

int main()
{
  Dog d;
  d.PrintAge();
  // cout << d.age << endl; /* Error */
}