// 20_this3.cpp
#include <iostream>
using namespace std;

class Sample
{
  // private 생성자
  //  의도: 외부에서 객체를 생성할 수 없습니다.
  // private:
  //   Sample() {}

  // private 소멸자
  //  의도: 객체를 오직 new를 통해서만 생성할 수 있습니다.

private:
  ~Sample() { cout << "소멸자 호출" << endl; }

public:
#if 0
  void Destroy(Sample *p)
  {
    delete p;
    // 소멸자 호출
  }
#endif
  void Destroy(/* Sample* this */)
  {
    delete this;
  }
};

// Sample g;

int main()
{
  Sample *p = new Sample;
  // p->Destroy(p);
  p->Destroy(); // => Sample::Destroy(p);

  // delete p;

  // Sample s;
  // Sample::Sample() 생성자 호출
}
// Sample::~Sample() 소멸자 호출