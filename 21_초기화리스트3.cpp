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