// // 37_STL5.cpp
#include <iostream>
using namespace std;

#include <algorithm>

// 1. 정책이 필요한 경우, 알고리즘 함수는 정책을 전달 받습니다.
//  => C++은 정책을 전달받는 함수는 템플릿으로 만들어져 있습니다.

// 2. 정책을 전달하는 방법
//  1) 일반 함수
//   => 인라인 함수라고 하더라도, 함수 포인터를 통해 호출하면, 인라인화가 불가능합니다.
bool func1(int a, int b)
{
  // printf("func1\n");
  return a > b;
}

//  2) 함수 객체
//  => 인라인화가 가능합니다.
struct Functor
{
  inline bool operator()(int a, int b) const { return a < b; }
};

int main()
{
  int x[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
  // sort(begin(x), end(x), &func1); // sort(int*, int*, bool(*)(int, int))

  // sort(begin(x), end(x), Functor()); // sort(int*, int*, Functor)

  // C++11에서 함수 객체를 편하게 사용할 수 있는 문법이 도입되었습니다.
  //  => 람다 표현식(Lambda Expression)
  //   : 익명의 함수 객체를 생성하는 문법
  sort(begin(x), end(x), [](int a, int b)
       { return a > b; });

  for (auto e : x)
    cout << e << endl;
}