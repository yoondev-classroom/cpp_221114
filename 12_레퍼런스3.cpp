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
  // 포인터는 잘못된 입력에 대한 검증이 반드시 필요합니다.
  if (user == NULL)
  {
    return;
  }

  // cout << (*user).name << ", " << (*user).age << endl;
  cout << user->name << ", " << user->age << endl;

  // 의도하지 않은 변경
  // user->age = 42; => 컴파일 오류
}

// C++에서 사용하는 방식입니다.
void PrintUser(const User &user)
{
  // 참조는 널 레퍼런스가 존재하지 않기 때문에,
  // 입력에 대한 검증이 필요하지 않습니다.

  cout << user.name << ", " << user.age << endl;
}

int main()
{
  const User user{"Tom", 42};

  cout << sizeof(User) << endl;

  // User user = {"Tom", 42};
  // User user{"Tom", 42};

  PrintUser(&user); // Call by pointer
  PrintUser(user);  // Call by reference

  User *pUser = NULL;
  PrintUser(pUser); /* 미정의 동작 */
}
