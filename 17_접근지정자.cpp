// 17_접근지정자
#include <iostream>
#include <string>
using namespace std;

// 1. struct: 기본 접근 지정자 public
//     class: 기본 접근 지정자 private

// 2. public: 외부에서 접근이 가능합니다.
//   private: 외부에서 접근이 불가능합니다.
//            friend로 선언된 함수와 클래스는 사용할 수 있습니다.

// 3. friend로 선언된 함수와 클래스는 자신의 private 멤버에 접근이 가능합니다.

class User
{
private:
  string name;
  int age;

public:
  User(string n, int a)
  {
    name = n;
    age = a;
  }

  // 방법 1. 접근자 메소드 / Getter
  // => 아래의 함수를 통해 누구나 필드에 값을 읽을 수 있습니다.
  string GetName() { return name; }
  int GetAge() { return age; }

  // 방법 2. friend
  // => 캡슐화의 정책을 깨뜨리지 않고, 캡슐화의 경계를 확장할 수 있습니다.
  friend void PrintUser(User user);
  friend class UserPrinter;
};

void PrintUser(User user)
{
  cout << user.name << ", " << user.age << endl;
}

class UserPrinter
{
public:
  void PrintUser(User user)
  {
    cout << user.name << ", " << user.age << endl;
  }
};

int main()
{
  // User user{"Tom", 42};
  User user("Tom", 42);

  // friend
  UserPrinter printer;
  printer.PrintUser(user);

  PrintUser(user);

  // getter
  cout << user.GetName() << ", " << user.GetAge() << endl;

  // 오류: private은 외부에서 접근이 불가능하기 때문입니다.
  // cout << user.name << ", " << user.age << endl;
}