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

  // 2) Delete Function
  User(const User &rhs) = delete;

public:
  User(const char *s, int n)
      : age(n)
  {
    name = new char[strlen(s) + 1];
    strcpy(name, s);
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
  // user2.Print();
}