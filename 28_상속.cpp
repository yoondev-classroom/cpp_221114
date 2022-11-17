// 28_상속.cpp
// => 객체지향 언어의 핵심적인 문법중 하나입니다.
#include <iostream>
using namespace std;

#if 0
class Student
{
  string name;
  string address;
  int id;

public:
  const string &GetName() const { return name; }
  void SetName(const string &s) { name = s; }

  const string &GetAddress() const { return address; }
  void SetAddress(const string &s) { address = s; }

  int GetId() const { return id; }
  void SetId(int i) { id = i; }
};

class Teacher
{
  string name;
  string address;
  int major;

public:
  const string &GetName() const { return name; }
  void SetName(const string &s) { name = s; }

  const string &GetAddress() const { return address; }
  void SetAddress(const string &s) { address = s; }

  int GetMajor() const { return major; }
  void SetMajor(int i) { major = i; }
};

int main()
{
  Student s;
  s.SetAddress("Seoul");
  s.SetId(42);
  cout << s.GetAddress() << endl;
  cout << s.GetId() << endl;

  Teacher t;
  t.SetAddress("Suwon");
  t.SetMajor(100);
}
#endif

// 상속의 문법을 이용하면, 각 클래스의 공통의 속성과 기능을 하나의 클래스로 캡슐화할 수 있습니다.

class Person
{
  string name;
  string address;

public:
  const string &GetName() const { return name; }
  void SetName(const string &s) { name = s; }

  const string GetAddress() const { return address; }
  void SetAddress(const string &s) { address = s; }
};

class Student : public Person
{
  int id;

public:
  int GetId() const { return id; }
  void SetId(int i) { id = i; }
};

class Teacher : public Person
{
  int major;

public:
  int GetMajor() const { return major; }
  void SetMajor(int i) { major = i; }
};

int main()
{
  Student s;
  s.SetAddress("Seoul");
  s.SetId(42);
  cout << s.GetAddress() << endl;
  cout << s.GetId() << endl;

  Teacher t;
  t.SetAddress("Suwon");
  t.SetMajor(100);
}