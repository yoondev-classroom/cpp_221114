// 33_연산자오버로딩5.cpp
#include <iostream>
using namespace std;
#if 0
namespace xstd
{
  class ostream
  {
  public:
    ostream &operator<<(int n)
    {
      printf("%d", n);
      return *this;
    }
    ostream &operator<<(const char *s)
    {
      printf("%s", s);
      return *this;
    }
    ostream &operator<<(double d)
    {
      printf("%.2lf", d);
      return *this;
    }

    ostream &operator<<(ostream &(*f)(ostream &))
    {
      // f(*this);
      // return *this;

      return f(*this);
    }
  };

  ostream cout;

  // endl 함수의 형태입니다.
  ostream &endl(ostream &os)
  {
    return os << "\n";
  }
}

// 1. endl은 함수입니다.
// 2. endl => IO Manipulator(IO 조정자)


int main()
{
  xstd::cout << "hello world" << xstd::endl;

  xstd::cout << "hello world";
  xstd::cout << xstd::endl;
  //   cout.operator<<(endl)

  // endl(xstd::cout);
  // 퀴니그 인자 검색 => 인자의 네임스페이스를 통해 함수의 네임스페이스를
  //                 암묵적으로 추론이 가능합니다.
}
#endif

// 3. 사용자 정의 조정자를 추가할 수 있습니다.
ostream &menu(ostream &os)
{
  os << "1. 짜장면" << endl;
  os << "2. 짬뽕" << endl;
  return os;
}

int main()
{
  cout << menu;
}