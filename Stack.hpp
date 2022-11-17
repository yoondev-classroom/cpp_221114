// Stack.hpp

#ifndef STACK_HPP
#define STACK_HPP

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

template <typename TYPE>
class Stack
{
private:
  TYPE *buff;
  int top;

public:
  inline ~Stack();

  inline Stack(int size);
  inline Stack();

  inline void push(const TYPE &n);
  inline TYPE pop();
};

template <typename TYPE>
Stack<TYPE>::~Stack()
{
  delete[] buff;
}

template <typename TYPE>
Stack<TYPE>::Stack(int size)
{
  top = 0;
  buff = new TYPE[size];
}

template <typename TYPE>
Stack<TYPE>::Stack()
{
  top = 0;
  buff = new TYPE[10];
}

template <typename TYPE>
void Stack<TYPE>::push(const TYPE &n)
{
  buff[top++] = n;
}

template <typename TYPE>
TYPE Stack<TYPE>::pop()
{
  return buff[--top];
}

#endif