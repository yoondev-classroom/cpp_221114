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

int main()
{
  Stack<int> s1;

  s1.push(10);
  s1.push(20);
  s1.push(30);

  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
}

#if 0
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