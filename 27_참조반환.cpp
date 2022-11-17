// 27_참조반환.cpp
#include <iostream>
#include <string>
using namespace std;

#if 0
class User
{
  string name_;
  int age_;
  string address_;
  string company_;

public:
  // Setter 메소드
  void SetName(const string &name)
  {
    name_ = name;
  }

  void SetAddress(const string &address)
  {
    address_ = address;
  }

  void SetCompany(const string &company)
  {
    company_ = company;
  }

  void SetAge(int age)
  {
    age_ = age;
  }
};

int main()
{
  User user;
  user.SetName("Tom");
  user.SetAge(42);
  user.SetAddress("Seoul");
  user.SetCompany("Hyundai");
}

#endif

#if 0
class User
{
  string name_;
  int age_;
  string address_;
  string company_;

public:
  // Setter 메소드
  User *SetName(const string &name)
  {
    name_ = name;
    return this;
  }

  User *SetAddress(const string &address)
  {
    address_ = address;
    return this;
  }

  User *SetCompany(const string &company)
  {
    company_ = company;
    return this;
  }

  User *SetAge(int age)
  {
    age_ = age;
    return this;
  }
};

int main()
{
  User user;
  user.SetName("Tom");
  user.SetAge(42);
  user.SetAddress("Seoul");
  user.SetCompany("Hyundai");

  User user;
  user.SetName("Tom")
      ->SetAge(42)
      ->SetAddress("Seoul")
      ->SetCompany("Hyundai");
}
#endif

class User
{
  string name_;
  int age_;
  string address_;
  string company_;

public:
  // Setter 메소드
  User &SetName(const string &name)
  {
    name_ = name;
    return *this;
  }

  User &SetAddress(const string &address)
  {
    address_ = address;
    return *this;
  }

  User &SetCompany(const string &company)
  {
    company_ = company;
    return *this;
  }

  User &SetAge(int age)
  {
    age_ = age;
    return *this;
  }
};

class Point
{
public:
  Point &Move(int x, int y) { return *this; }
  Point &Transform() { return *this; }

  int Result() { return 42; }
};

int main()
{
  Point pt;
  pt.Move(10, 10)
      .Move(0, 0)
      .Transform()
      .Move(10, 20)
      .Transform()
      .Result();

  User user;
  user.SetName("Tom");
  user.SetAge(42);
  user.SetAddress("Seoul");
  user.SetCompany("Hyundai");

  // 자기 자신의 참조를 반환하는 멤버 함수를 사용하는 방법
  user.SetName("Tom")
      .SetAge(42)
      .SetAddress("Seoul")
      .SetCompany("Hyundai");
}