// Stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>

// > 절대 헤더파일에 작성하면 안됩니다.
// using std::cout;
// using std::endl;

// using namespace std;

// 헤더 파일에서는 반드시 전체 이름 공간을 명시해야 합니다.

class Stack
{
private:
  int *buff;
  int top;

public:
  //-----
  // inline ~Stack()
  ~Stack()
  {
    std::cout << "~Stack()" << std::endl;
    delete[] buff;
  }

  Stack(int size);
  Stack();

  // 인라인 함수의 경우,
  // 반드시 구현이 헤더파일을 통해 제공되어야 합니다.
  // inline은 선언에만 작성해야 합니다.
  inline void push(int n);
  inline int pop();
};

void Stack::push(int n)
{
  buff[top++] = n;
}

int Stack::pop()
{
  return buff[--top];
}

#endif