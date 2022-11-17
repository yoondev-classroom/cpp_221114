// 22_복사생성자3.cpp
#include <iostream>
using namespace std;

class Sample
{
public:
  Sample() {}
  Sample(const Sample &rhs) { cout << "Sample(const&)" << endl; }
  ~Sample() { cout << "~Sample()" << endl; }
};

// 복사 생성자가 호출되는 경우
// 1) 객체가 함수의 인자로 값으로 전달될 때
#if 0
void foo(Sample x) // x: Sample(const&)
{
  // 읽기
}
// x: ~Sample()
#endif

// 해결 방법: 객체를 call by value로 전달할 때는
//          같은 의도를 가지고 있는, const&를 사용해야 합니다.
void foo(const Sample &x)
{
}

int main()
{
  Sample s;
  foo(s);
}

// 결론
//  - int, double, char .. 크기가 크기 않은 타입
// void foo(int a) /* OK */

//  - 객체 타입
// void foo(User user);        /* NO */
// void foo(const User &user); /* OK */

// - 템플릿 T
// template <typename T>
// void foo(const T&)
//   T   ->  int ==> const int&
// User  -> User ==> const User&