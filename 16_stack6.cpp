// 16_stack5.cpp
#include <iostream>
using namespace std;

// 문제점
//  - 사용자가 원하는 크기의 스택을 생성하도록 하고 싶습니다.
// 해결 방법
//  - 생성자는 인자를 통해 값을 전달받을 수 있습니다.
//  - 생성자는 오버로딩이 가능합니다.

class Stack
{
private:
  int buff[10];
  int top;

public:
  //-----
  Stack(int size)
  {
    cout << "Stack(int)" << endl;
  }

  Stack()
  {
    cout << "Stack()" << endl;
    top = 0;
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

// 생성자에 인자를 전달하는 방법
int main()
{
  // Direct Initialization
  Stack s1;      // Stack()
  Stack s2(100); // Stack(int)
  Stack s3{100}; // Stack(int)

  // Copy Initialization
  Stack s4 = 100;   // Stack(int)
  Stack s5 = {100}; // Stack(int)
}

#if 0
int main()
{
  cout << "main" << endl;
  Stack s1;
  // s1.init();

  s1.push(10);
  s1.push(20);
  s1.push(30);

  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
}
#endif