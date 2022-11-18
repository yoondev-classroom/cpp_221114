// 28_상속5.cpp
#include <iostream>
using namespace std;

#if 1
class Base
{
public:
  Base(int n) {}
  Base(int a, int b) {}
  Base(int a, int b, int c) {}
};

class Derived : public Base
{
public:
  // 컴파일러가 만들어주는 생성자
  // Derived(): Base() {}

  Derived() : Base(42) {}
};

// 에러: 부모의 기본 생성자가 없는 경우,
//      컴파일러가 자동으로 생성하는 기본 생성자에서는
//      부모의 기본 생성자를 호출하고자 하기 때문입니다.

// 해결 방법
//  => 부모가 기본 생성자를 제공하지 않는 경우, 반드시 초기화리스트를 통해 부모의 생성자를
//     명시적으로 호출해야 합니다.

int main()
{
  Derived d;
}
#endif

#if 0
class Base
{
private:
  int ba_;
  int bb_;

public:
  Base(int ba, int bb) : ba_(ba), bb_(bb) {}
};

class Derived : public Base
{
  int a_;
  int b_;

public:
  // 자식의 생성자는 반드시 부모의 생성자를 초기화하는데 필요한 인자도 전달받아야 합니다.
  Derived(int ba, int bb, int a, int b)
      : Base(ba, bb), a_(a), b_(b)
  {
  }
};
#endif

#if 0
class Student
{
  string name;
  string address;
  int id;

public:
  Student(const string &n, const string &a, int i)
      : name(n), address(a), id(i)
  {
  }

  const string &GetName() const { return name; }
  void SetName(const string &s) { name = s; }

  const string &GetAddress() const { return address; }
  void SetAddress(const string &s) { address = s; }

  int GetId() const { return id; }
  void SetId(int i) { id = i; }
};
#endif

class Person
{
  string name;
  string address;

public:
  Person(const string &n, const string &a)
      : name(n), address(a)
  {
  }

  const string &GetName() const { return name; }
  void SetName(const string &s) { name = s; }

  const string &GetAddress() const { return address; }
  void SetAddress(const string &s) { address = s; }
};

class Student : public Person
{
  int id;

public:
  Student(const string &n, const string &a, int i)
      : Person(n, a), id(i)
  {
  }

  int GetId() const { return id; }
  void SetId(int i) { id = i; }
};

int main()
{
}