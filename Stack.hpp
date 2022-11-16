// Stack.hpp

#ifndef STACK_HPP
#define STACK_HPP

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

  void push(TYPE n)
  {
    buff[top++] = n;
  }

  TYPE pop()
  {
    return buff[--top];
  }
};

#endif