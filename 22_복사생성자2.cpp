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