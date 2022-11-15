// Stack.cpp

// 1. 헤더 파일 포함이 필요합니다.
#include "Stack.h"

// 2. 멤버 함수의 이름 앞에 클래스의 이름을
//    명시해야 합니다.

Stack::Stack(int size)
{
  std::cout << "Stack(int)" << std::endl;
  top = 0;
  buff = new int[size];
}

Stack::Stack()
{
  std::cout << "Stack()" << std::endl;
  top = 0;
  buff = new int[10];
}

// inline 함수 아닐 때
#if 0
Stack::~Stack()
{
  std::cout << "~Stack()" << std::endl;
  delete[] buff; // !!!
}


void Stack::push(int n)
{
  buff[top++] = n;
}

int Stack::pop()
{
  return buff[--top];
}
#endif