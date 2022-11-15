// 16_stack4.cpp
#include <iostream>
using namespace std;

// 객체의 상태는 멤버 함수(메소드)를 통해서만
// 접근할 수 있어야 합니다.
//  => 정보 은닉(Information Hiding)
//  => 접근 지정자
//    public: 외부에서 접근이 가능합니다.
//    private: 외부에서 접근이 불가능하고,
//            멤버 함수를 통해서만 접근이 가능합니다.

struct Stack
{
private:
  // 멤버 데이터(상태)
  int buff[10];
  int top;

public:
  // 멤버 함수(행위)
  void init()
  {
    top = 0;
  }

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
  Stack s1;
  s1.init();

  s1.push(10);
  s1.push(20);
  s1.push(30);

  // s1.top = 5; /* 잘못된 외부에서의 상태 변경 */
  // cout << s1.top << endl;

  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
}