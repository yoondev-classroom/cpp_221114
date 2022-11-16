// 19_소멸자.cpp
#include <iostream>

#include <cstring>
using namespace std;

// 1. 소멸자 함수는 ~클래스이름() 형태 입니다.
//    반환값도 없고, 반환타입도 명시하지 않습니다.
//    인자도 없습니다.
//    오버로딩 불가능하고, 오직 1개만 제공할 수 있습니다.

// 2. 사용자가 소멸자를 제공하지 않으면, 컴파일러는 아무일도 하지 않는
//    소멸자를 만들어줍니다.

// 3. 소멸자를 반드시 제공해야 하는 경우
// => 객체 내부에서 자원(메모리, 비메모리)을 할당할 경우,
//    객체가 파괴되는 시점에 자원을 정리해야 합니다.

class User
{
  char *name;

public:
  User(const char *s)
  {
    cout << "User(): 메모리 할당" << endl;
    name = new char[strlen(s) + 1];
    strcpy(name, s);
  }

  // 컴파일러가 제공하는 소멸자 형태
  // ~User() {}

  ~User()
  {
    cout << "~User(): 메모리 해지" << endl;
    delete[] name;
  }
};

int main()
{
  User user("Tom");
}