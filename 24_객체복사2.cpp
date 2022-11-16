// 24_객체복사2.cpp
#include <iostream>
using namespace std;

// 3. 해결 방법 3가지
//  1) 깊은 복사

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

  // 깊은 복사
  User(const User &rhs)
      : age(rhs.age)
  {
    name = new char[strlen(rhs.name) + 1];
    strcpy(name, rhs.name);
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