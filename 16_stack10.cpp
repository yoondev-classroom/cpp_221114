// 16_stack.cpp
#include <iostream>
using namespace std;

// 이미 C++의 표준 라이브러리에 stack이 있습니다.
//  => STL(Standard Template Library)

#include <stack>

int main()
{
  stack<int> s;

  s.push(10);
  s.push(20);
  s.push(30);

  // STL의 자료구조(컨테이너)는 데이터를 접근하는 연산과
  // 데이터를 제거하는 연산이 분리되어 있습니다.

  cout << s.top() << endl;
  s.pop();

  cout << s.top() << endl;
  s.pop();

  cout << s.top() << endl;
  s.pop();
}