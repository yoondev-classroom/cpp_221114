// 20_this2.cpp
#include <iostream>
using namespace std;

class Sample
{
  int data = 100;

public:
  // void f1(Sample* this)
  void f1() { cout << "f1" << endl; }

  // void f1(Sample* this)
  void f2()
  {
    cout << "f2: " << data << endl;
    //              this->data
  }
};

int main()
{
  // Sample s;
  // s.f1();

  Sample *p = nullptr;
  // p->f1(); // Sample::f1(p);
  p->f2();
}