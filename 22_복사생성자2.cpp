// 22_복사생성자2.cpp
#include <iostream>
using namespace std;

class Sample
{
public:
  Sample() {}
  Sample(const Sample &rhs) { cout << "Sample(const&)" << endl; }
  ~Sample() { cout << "~Sample()" << endl; }
};

// 객체가 call by value로 전달할 때
void foo(Sample s)
{
}

// 객체가 함수에서 값으로 반환될 때,
// 값을 반환하기 위한 임시 객체가 생성되고(복사 생성자 호출)
// 임시 객체는 표현식을 벗어난 이후 사라집니다.
Sample g;
Sample goo()
{
  return g;
}

int main()
{
  // Sample s;
  // foo(s);

  goo();
  // ...
}

#if 0
int main()
{
  Sample s1;

  // 복사 생성자가 호출되는 경우
  Sample s2 = s1;
  Sample s3(s1);
  Sample s4 = {s1};
  Sample s5{s1};
}
#endif