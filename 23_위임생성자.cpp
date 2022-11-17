// 23_위임생성자.cpp
#include <iostream>
#include <string>
using namespace std;

#if 0
class User
{
  string id_;

private:
  void init_process1() {}
  void init_process2() {}
  void init_process3() {}

public:
  User(const string &id)
      : id_(id)
  {
    init_process1();
    init_process2();
    init_process3();
  }

  User(const string &name, int age)
      : id_(name + "@" + to_string(age))
  {
    init_process1();
    init_process2();
    init_process3();
  }
};
#endif

// 위임 생성자 - C++11
//  정의: 자신의 다른 생성자를 통해 객체를 초기화할 수 있습니다.
//    "생성자에서 다른 생성자를 호출할 수 있습니다."

//  효과
//    - 생성자 코드에서 발생하는 중복을 제거할 수 있습니다.

class User
{
  string id_;

private:
  void init_process1() {}
  void init_process2() {}
  void init_process3() {}

public:
  // Primary Constructor: 주 생성자
  // Designated Initializer: 지정 초기화 함수
  User(const string &id)
      : id_(id)
  {
    init_process1();
    init_process2();
    init_process3();
  }

  User(const string &name, int age)
      : User(name + "@" + to_string(age)) // 위임 생성자!
  {
    // User(name + "@" + to_string(age)); // 임시 객체 생성 문법
  }
};

int main()
{
}