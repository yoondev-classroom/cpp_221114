// 35_함수객체.cpp
#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }

// 1. 함수 호출 연산자를 재정의하면, 함수처럼 사용할 수 있습니다.
//  => 함수 객체

// 2. 함수 호출 연산자는 함수의 인자와 반환 타입을 자유롭게 지정할 수 있습니다.

// 3. 함수 호출 연산자 재정의는 반드시 멤버 함수를 통해서만 제공해야 합니다.

class Adder
{
public:
  int operator()(int a, int b) const
  {
    return a + b;
  }
};

int main()
{
  // int result = add(10, 20);
  // cout << result << endl;

  Adder adder;
  int result = adder(10, 20);
  //           adder.operator()(10, 20)

  cout << result << endl;
}