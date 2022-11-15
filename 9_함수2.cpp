// 2_함수2.cpp
#include <iostream>
using namespace std;

#if 0
int square(int x) { return x * x; }

int main()
{
  cout << square(10) << endl;
  cout << square(3.14) << endl;
}
#endif

// C는 동일한 이름의 함수를 여러개 제공할 수 없습니다.
#if 0
int squarei(int x) { return x * x; }
double squared(double x) { return x * x; }
long long squarell(long long x) { return x * x; }

int main()
{
  cout << squarei(10) << endl;
  cout << squared(3.14) << endl;
  cout << squarell(100LL) << endl;
}
#endif

// C++은 함수의 인자의 타입이 다르고, 개수가 다른 경우, 동일한 이름의 함수를
// 여러개 제공할 수 있습니다.
//  => 함수 오버로딩(중복 적재)

int square(int x) { return x * x; }
double square(double x) { return x * x; }
long long square(long long x) { return x * x; }

// 함수 오버로딩의 원리: 네임 맹글링
// C:   int square(int)    {} => _square
//   double square(double) {} => _square

// C++: int square(int)    {} => __Z6squarei
//   double square(double) {} => __Z6squared
// extern "C" double square(double) {} => _square

// extern "C"
// => 네임 맹글링을 하지 않는 C의 함수 형태로 만듭니다.
// 1. C++ 프로그램에서 C의 함수를 호출할 때
// 2. C 프로그램에서 C++의 함수를 호출할 때

// => extern "C"로 지정된 함수는 오버로딩이 불가능합니다.

int main()
{
  cout << square(10) << endl;
  cout << square(3.14) << endl;
  cout << square(100LL) << endl;
}