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
    printf("%s, %d\n", name, age);

    // cout << name << ", " << age << endl;
  }

  User(const char *s, int n)
      : age(n)
  {
    // cout << "생성" << endl;

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

  // 소유권 이전
  User(User &&rhs) // Move constructor => C++11
  {
    cout << "소유권 이전" << endl;
    name = rhs.name;
    age = rhs.age;

    rhs.name = nullptr;
    rhs.age = 0;
  }

  ~User()
  {
    // cout << "파괴" << endl;
    delete[] name;
  }
};

User g("Bob", 100);
User foo()
{
  return g;
}

int main()
{
  User *user = new User("Tom", 42);
  // rvalue로 변경하는 방법: move
  // User user2(std::move(*user));

  /// User user2(User("Bob", 100)); // User user2("Bob", 100);
  User user2(std::move(foo()));
  // User user2(foo());
  g.Print();

  user->Print();
  user2.Print();

  delete user;
}

#if 0
int main()
{
  // User user1("Tom", 42);
  // User user2 = user1;

  cout << "------" << endl;
  // User("Tom", 42);

  // const User &cr = User("Tom", 42);
  User &&cr = User("Tom", 42);
  cout << "------" << endl;

  cout << "main 종료" << endl;
}
#endif

// 1. 임시 객체는 표현식을 벗어나면 사라집니다.
// 2. 임시 객체는 참조를 통해 수명을 연장할 수 있습니다.
// 3. 임시 객체는 rvalue 입니다.
//   => const&
//      &&
