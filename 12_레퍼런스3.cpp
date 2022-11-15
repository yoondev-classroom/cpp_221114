// 12_레퍼런스3.cpp
#include <iostream>
#include <string>
using namespace std;

struct User
{
  std::string name;
  int age;

  char address[100];
};

// 문제점: 구조체를 값에 의한 호출을 사용하면,
//       구조체 크기 만큼의 복사 비용이 발생합니다.
#if 0
void PrintUser(User user)
{
  cout << user.name << ", " << user.age << endl;
}
#endif

// C에서 사용하는 방식입니다.
void PrintUser(const User *user)
{
  // cout << (*user).name << ", " << (*user).age << endl;
  cout << user->name << ", " << user->age << endl;

  // 의도하지 않은 변경
  // user->age = 42; => 컴파일 오류
}

void PrintUser(const User &user)
{
  cout << user.name << ", " << user.age << endl;
}

int main()
{
  const User user{"Tom", 42};

  cout << sizeof(User) << endl;

  // User user = {"Tom", 42};
  // User user{"Tom", 42};

  // PrintUser(user);
  // PrintUser(&user); // const User* -> User*

  PrintUser(user);
}
