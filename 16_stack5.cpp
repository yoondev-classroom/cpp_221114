// 16_stack5.cpp
#include <iostream>
using namespace std;

// 문제점
// - 객체를 생성하였을 때, 바로 사용할 수 없습니다.

// 해결 방법
// - 객체가 메모리에 생성되었을 때, 자동으로 호출되는 약속된 함수가 있습니다.
//   "생성자(Constructor) 함수"
//   => 객체를 생성하였을 때, 바로 사용할 수 있도록 초기화하는 역활을
//      담당합니다.

// 생성자 함수
// - 이름은 클래스 이름과 동일합니다.
// - 반환타입도 없고, 반환타입을 명시하지도 않습니다.

class Stack
{
private:
  int buff[10];
  int top;

public:
  //-----
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