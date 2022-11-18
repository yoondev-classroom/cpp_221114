// 30_가상함수의원리2.cpp
#include <iostream>
using namespace std;
// => 원리 파악을 위한 예제입니다.

class AAA
{
public:
  virtual void foo() { cout << "AAA foo" << endl; } // 1
};

// 주의: 부모 자식 관계가 아닙니다.
class BBB
{
public:
  virtual void goo()
  {
    cout << this << endl;
    cout << "BBB goo" << endl;
  } // 2
};

// 핵심: 정적 바인딩 / 동적 바인딩

int main()
{
  AAA aaa;
  cout << &aaa << endl;

  BBB *p = reinterpret_cast<BBB *>(&aaa);

  p->goo(); // 정적 바인딩: BBB::goo(p)
            // 동적 바인딩: (aaa->vftp)[0](p);
}