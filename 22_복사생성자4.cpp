// 22_복사생성자4.cpp
#include <iostream>
using namespace std;

class Sample
{
public:
  Sample() {}
  Sample(const Sample &rhs) { cout << "Sample(const&)" << endl; }
  ~Sample() { cout << "~Sample()" << endl; }
};

// 2) 함수가 객체를 값으로 반환할 때

#if 0
Sample s; // s: Sample()
Sample foo()
{
  return s;
  // 1. s를 복제한, 임시 객체가 생성됩니다. => 복사 생성자 호출
}

int main()
{
  foo();
  //-----
  // 2. 임시 객체의 수명은 종료되고, 임시 객체가 파괴되면서 소멸자가 호출됩니다.

  cout << "main 종료" << endl;
}
// s: ~Sample()
#endif

Sample s;

// 핵심: 반환할 때, '참조로 반환'하면, 임시 객체가 생성되지 않습니다.
Sample &foo()
{
  return s;
}

int main()
{
  foo();

  cout << "main 종료" << endl;
}