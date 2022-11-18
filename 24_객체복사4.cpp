// 24_객체복사4.cpp
#include <iostream>
using namespace std;

// 3. 해결 방법 3가지
//  3) 복사 금지 + 소유권 이동 => 자원 독점
class User
{
private:
  char *name;
  int age;

  // 복사 생성자 금지 방법 1.
  // 1) private 영역에 선언만 합니다. => 링크 오류
  //   User(const User &rhs);
  //   User& operator=(const User& rhs);

  // 2) Delete Function - C++11
  User(const User &rhs) = delete;
  User &operator=(const User &rhs) = delete;

public:
  User(const char *s, int n)
      : age(n)
  {
    name = new char[strlen(s) + 1];
    strcpy(name, s);
  }

  // Move 생성자
  User(User &&rhs)
      : name(rhs.name), age(rhs.age)
  {
    rhs.name = nullptr;
    rhs.age = 0;
  }

  // Move 연산자
  User &operator=(User &&rhs)
  {
    if (this == &rhs)
      return *this;

    delete[] name;

    name = rhs.name;
    age = rhs.age;

    rhs.name = nullptr;
    rhs.age = 0;

    return *this;
  }

  ~User()
  {
    delete[] name;
  }

  void Print()
  {
    // cout << name << ", " << age << endl;
    printf("%s, %d\n", name, age);
  }
};

int main()
{
  User user1("Tom", 42);
  user1.Print();

  // User user2 = user1; /* 복사 금지 */

  User user2 = std::move(user1); /* 소유권 이전은 가능합니다. */
  user1.Print();
  user2.Print();

  User user3("Bob", 100);
  user3 = std::move(user2);
  user2.Print();
  user3.Print();
}