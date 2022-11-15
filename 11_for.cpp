// 11_for.cpp
#include <cctype>
#include <iostream>
using namespace std;

int main()
{
  double x[5] = {1.1, 2.2, 3.3, 4, 5};

  for (int i = 0; i < sizeof(x) / sizeof(x[0]); ++i)
  {
    cout << x[i] << endl;
  }

  // C++11, index가 필요하지 않다면
  //  => Ranged-for
  for (auto e : x)
  {
    cout << e << endl;
  }

  // 순회 가능한(Iterable) 타입에 대해서 사용할 수 있습니다.
  string s = "hello world hello world";
  for (auto e : s)
  {
    cout << (char)toupper(e) << endl;
  }
}