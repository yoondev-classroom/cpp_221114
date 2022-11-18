// 37_STL4.cpp
#include <iostream>
using namespace std;

// find: 컨테이너에서 요소를 찾는 함수

// 1. 존재하지 않는 경우, past the end를 반환합니다.
#if 0
int *xfind(int *first, int *last, int value)
{
  while (first != last && *first != value)
    ++first;

  // return first == last ? nullptr : first;
  return first;
}
#endif

// 아래처럼 만들면 포인터만 사용할 수 있습니다.
// => 스마트 포인터 같은 객체도 사용해야 합니다.
// template <typename T>
// T *xfind(T *first, T *last, T value)

template <typename T, typename F>
T xfind(T first, T last, F value)
{
  while (first != last && *first != value)
    ++first;

  return first;
}

// 알고리즘
//  정의: STL에서 컨테이너 저장된 데이터를 대상으로 다양한 연산을 수행할 수 있는
//       알고리즘 함수를 제공합니다
//  핵심: 알고리즘 함수는 멤버 함수가 아닌 일반 함수를 통해 제공됩니다.

// list
// vector ----> find() ...
// array
//  ...

#include <algorithm> // find
#include <vector>
#include <list>

int main()
{
  //          f              l
  // int x[5] = {1, 2, 3, 4, 5};
  list<int> x = {1, 2, 3, 4, 5};

  auto p = find(begin(x), end(x), 3);
  if (p != end(x))
  {
    cout << *p << endl;
  }
}