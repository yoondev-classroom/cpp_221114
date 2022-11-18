// 33_연산자오버로딩2.cpp
#include <iostream>
using namespace std;

namespace xstd
{
  class istream
  {
  public:
    istream &operator>>(int &n)
    {
      scanf("%d", &n);
      return *this;
    }

    istream &operator>>(double &d)
    {
      scanf("%lf", &d);
      return *this;
    }
  };

  istream cin;
}

int main()
{
  int n;
  double d;
  xstd::cin >> n >> d;
  cout << n << ", " << d << endl;
}

#if 0
int main()
{
  int n;
  cin >> n;
  cout << n << endl;

  double d;
  cin >> d;
  cout << d << endl;
}
#endif