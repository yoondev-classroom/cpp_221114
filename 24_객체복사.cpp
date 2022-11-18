// 24_객체복사.cpp
#include <iostream>
using namespace std;

// 1. 소멸자를 반드시 정의해야 하는 경우
// => 객체 내부에서 자원을 할당한 경우

// 2. 복사 생성자/대입 연산자를 반드시 직접 정의해야 하는 경우
// => 객체가 포인터 멤버 데이터를 가지는 경우
//    반드시 복사 생성자/대입연산자를 제공해서, 얕은 복사(Shallow Copy)의 문제를
//    해결해야 합니다.

// 3. 해결 방법 3가지
//  1) 깊은 복사
//  2) 참조 계수
//  3) 복사 금지

class User
{
private:
  char *name;
  int age;

public:
  User(const char *s, int n)
      : age(n)
  {
    name = new char[strlen(s) + 1];
    strcpy(name, s);
  }

  // 컴파일러가 기본으로 만들어주는 복사 생성자 형태
  User(const User &rhs)
      : name(rhs.name), age(rhs.age)
  {
  }

  ~User()
  {
    delete[] name;
  }

  void Print()
  {
    cout << name << ", " << age << endl;
  }
};

int main()
{
  User user1("Tom", 42);
  user1.Print();

  User user2 = user1;
  user2.Print();
}