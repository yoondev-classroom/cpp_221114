// 25_소유권이동.cpp
#include <iostream>
using namespace std;

class User
{
private:
  char *name;
  int age;

public:
  void Print()
  {
    cout << name << ", " << age << endl;
  }

  User(const char *s, int n)
      : age(n)
  {
    cout << "생성" << endl;

    name = new char[strlen(s) + 1];
    strcpy(name, s);
  }

  User(const User &rhs)
      : age(rhs.age)
  {
    cout << "복사" << endl;
    name = new char[strlen(rhs.name) + 1];
    strcpy(name, rhs.name);
  }

  ~User()
  {
    cout << "파괴" << endl;
    delete[] name;
  }
};

int main()
{
  // User user1("Tom", 42);
  // User user2 = user1;

  cout << "------" << endl;
  // const User &cr = User("Tom", 42);
  User &&cr = User("Tom", 42);
  cout << "------" << endl;

  cout << "main 종료" << endl;
}

// 1. 임시 객체는 표현식을 벗어나면 사라집니다.
// 2. 임시 객체는 참조를 통해 수명을 연장할 수 있습니다.
// 3. 임시 객체는 rvalue 입니다.
//   => const&
//      &&
