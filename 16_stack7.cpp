// 16_stack5.cpp
#include <iostream>
using namespace std;

// 문제점
//  - 객체 내부에서 new한 메모리는 객체가 파괴되는 시점에 delete 되어야 합니다.

// 해결 방법
//  - 객체가 메모리에서 해지되기 전에 호출되는 약속된 함수가 있습니다.
//   => 소멸자(Destructor) 함수
//     - 객체 내부에서 해지해야 하는 자원(메모리, 파일, 스레드)이 존재하는 경우,
//       소멸자를 통해 반드시 정리해야 합니다.

// 소멸자
// - ~클래스 이름입니다.
// - 반환 타입도 없고, 반환값도 없습니다.
// - 인자도 없습니다. 오버로딩도 불가능합니다.
// - 오직 1개만 제공할 수 있습니다.

class Stack
{
private:
  int *buff;
  int top;

public:
  //-----
  ~Stack()
  {
    cout << "~Stack()" << endl;
    delete[] buff; // !!!
  }

  Stack(int size)
  {
    cout << "Stack(int)" << endl;
    top = 0;
    buff = new int[size];
  }

  Stack()
  {
    cout << "Stack()" << endl;
    top = 0;
    buff = new int[10];
  }
  //-----

  // void init() { top = 0; }

  void push(int n)
  {
    buff[top++] = n;
  }

  int pop()
  {
    return buff[--top];
  }
};

int main()
{
  cout << "main" << endl;
  // Stack s1(100);
  Stack s1;

  s1.push(10);
  s1.push(20);
  s1.push(30);

  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
  cout << s1.pop() << endl;

  cout << "main end" << endl;
}
