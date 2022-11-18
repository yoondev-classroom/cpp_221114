// 35_함수객체.cpp
#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }

// 함수 호출 연산자를 재정의하면, 함수처럼 사용할 수 있습니다.
//  => 함수 객체
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