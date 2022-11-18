// 37_STL3.cpp
#include <iostream>
using namespace std;

// 반복자(Iterator)

// 1. 배열의 끝 다음 위치에 대해서 포인터를 통해
//    가르키는 것은 유효합니다.

#if 0
int main()
{
  //         p1              p2
  int x[5] = {1, 2, 3, 4, 5};
  // int *p1 = &x[2];

  int *p1 = x;
  int *p2 = &x[5]; /* OK */

  while (p1 != p2)
  {
    cout << *p1 << endl;
    ++p1;
  }
}
#endif

// begin: 컨테이너의 시작 위치를 얻는 함수
//   end: 컨테이너의 끝 다음 위치를 얻는 함수, past the end
// [begin, end) => 반개구간

#if 0
int main()
{
  //         p1              p2
  int x[5] = {1, 2, 3, 4, 5};
  // int *p1 = &x[2];

  // auto p1 = x;
  // auto p2 = &x[5]; /* OK */
  auto p1 = begin(x);
  auto p2 = end(x);

  while (p1 != p2)
  {
    cout << *p1 << endl;
    ++p1;
  }
}
#endif
#include <vector>
#include <list>
#include <array>

int main()
{
  // int x[5] = {1, 2, 3, 4, 5};
  array<int, 5> x = {1, 2, 3, 4, 5};
  // vector<int> x = {1, 2, 3, 4, 5};

  // - 일반 배열은 .begin / .end 멤버함수가 없습니다.
  // auto p1 = x.begin(); // 반복자: 컨테이너의 요소를 가르키는 타입
  // auto p2 = x.end();

  auto p1 = begin(x);
  auto p2 = end(x);

  while (p1 != p2) // 비교
  {
    cout << *p1 << endl; // 참조
    ++p1;                // 다음으로 이동
  }
}