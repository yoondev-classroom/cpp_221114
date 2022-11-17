// 16_stack9.cpp
#include <iostream>
#include <string>
using namespace std;

// 문제점
// => 스택이 int 타입에 대해서만 사용할 수 있습니다.
//    타입만 다르고 스택의 알고리즘은 항상 동일합니다.
// 해결 방법
// => 클래스도 템플릿으로 만들 수 있습니다.

// 클래스 템플릿
// => 템플릿의 타입을 컴파일러가 결정할 수 없을 수 있고,
//    명시적으로 타입을 지정해야 합니다.
#if 0
template <typename TYPE>
class Stack
{
private:
  TYPE *buff;
  int top;

public:
  ~Stack()
  {
    delete[] buff;
  }

  Stack(int size)
  {
    top = 0;
    buff = new TYPE[size];
  }

  Stack()
  {
    top = 0;
    buff = new TYPE[10];
  }

  // TYPE: int => void push(int n)
  // TYPE: string => void push(string n)
  // => TYPE은 기본 타입 뿐 아니라 객체도 사용할 수 있습니다.

  // TYPE: int => void push(const int& n)
  // TYPE: string => void push(const string& n)
  void push(const TYPE &n)
  {
    buff[top++] = n;
  }

  TYPE pop()
  {
    return buff[--top];
  }
};
#endif

// 템플릿(함수 템플릿, 클래스 템플릿)은 헤더와 소스의 분리가 불가능합니다.
// => 반드시 헤더를 통해서만 제공해야 합니다.
//  Stack.h + Stack.cpp  => Stack.hpp

#include "Stack.hpp"

//       Stack: 클래스 템플릿
// Stack<TYPE>: 클래스

#if 0
int main()
{
  Stack<int> s1;
  s1.push(10);
  s1.push(20);
  s1.push(30);

  Stack<string> s2;
  s2.push("hello");
}
#endif

#if 1
int main()
{
  Stack<string> s1;

  s1.push("hello");
  s1.push("world");
  s1.push("show");

  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
}
#endif