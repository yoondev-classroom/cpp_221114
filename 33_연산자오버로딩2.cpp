// 33_연산자오버로딩2.cpp

#include <iostream>

#if 0
namespace std {
  class ostream {
  };
  ostream cout;
}
#endif

namespace xstd
{
  class xostream
  {
  public:
    xostream &operator<<(int n)
    {
      printf("%d", n);
      return *this;
    }
    xostream &operator<<(const char *s)
    {
      printf("%s", s);
      return *this;
    }
    xostream &operator<<(double d)
    {
      printf("%.2lf", d);
      return *this;
    }
  };

  xostream cout;
}

int main()
{
  int n = 42;
  double d = 3.14;

  xstd::cout << n << ", " << d;
  //  cout.operator<<(n)
  //      .operator<<(", ")
  //      .operator<<(d);

  xstd::cout << n;
  // cout.operator<<(n)

  xstd::cout << ", ";
  // cout.operator<<(n)

  xstd::cout << d;
  // cout.operator<<(d)
}