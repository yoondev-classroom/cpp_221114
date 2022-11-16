// 21_초기화리스트3.cpp

#include <iostream>
#include <string>
using namespace std;

// * 멤버 데이터 이름 규칙
// 1) name
//   => 파라미터와 구분할 수 없는 경우, this-> 명시해야 합니다.
// 2) m_name, mName: MFC
// 3) name_: C++
// 4) _name: MS

#if 0
class User
{
  string name;
  int age;

public:
  User(string name, int age)
      : name(name), age(age)
  {
    // 1. 초기화리스트는 파라미터와 멤버가 구분됩니다.
  }

  void SetName(string name)
  {
    // 2. 파라미터와 멤버 데이터를 구분하기 위해 this-> 명시적으로 작성해야 합니다.
    this->name = name;
  }

  void Print() { cout << name << ", " << age << endl; }
};

int main()
{
  User user("Tom", 42);
  user.Print();
}
#endif

// C++에서 멤버 데이터를 초기화하는 방법 2가지
class User
{
  // 1. 필드 초기화: C++11
  string name_ = "Bob";
  int age_ = 0;

public:
  // 2. 초기화 리스트 => 우선순위가 높습니다.
  User(string name, int age)
      : name_(name), age_(age) {}

  void Print() { cout << name_ << ", " << age_ << endl; }
};

int main()
{
  User user("Tom", 42);
  user.Print();
}