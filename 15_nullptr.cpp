// 15_nullptr.cpp
#include <iostream>
using namespace std;

// NULL => 0

void foo(int n) { cout << "int" << endl; }
void foo(int *p) { cout << "int *" << endl; }

// C++11에서 NULL을 대체하는 nullptr을 만들었습니다.
int main()
{
  int *p1 = nullptr;
  foo(nullptr); // int *

  // nullptr은 NULL을 대체합니다.
  //  => nullptr의 정확한 타입은 nullptr_t 입니다.

  int *p2 = nullptr;
  void *p3 = nullptr;
  char *p4 = nullptr;

  // nullptr -> bool(false)
  // - bool 타입으로의 암묵적인 변환이 허용되고, NULL과 동일하게 false로 판단됩니다.
  if (!p1)
  {
    cout << "p1 == nullptr" << endl;
  }

  // C++은 bool 타입이 있습니다.
  bool b = true;
  // b = false;
  cout << b << endl;
}

#if 0
int main()
{
  // 1. 정수 0은 포인터 타입으로의 암묵적인 변환이 허용됩니다.
  // int* p1 = 0;

  // int *p2 = 10; /* Compile error */

  int *p1 = NULL;
  foo(p1);

  // 2. NULL은 정수와 포인터 타입간의 모호성 오류가 발생할 수 있습니다.
  foo(NULL); // 모호성 오류

  // 3. NULL은 타입 안정성이 없습니다.
}
#endif