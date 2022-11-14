// 9_함수4.cpp
#include <iostream>
using namespace std;

int square(int x) { return x * x; }

// 매크로 함수
// > C 에서는 함수 호출의 오버헤드를 제거하기 위해서,
//   매크로 함수를 이용합니다.

#define SQUARE(x) ((x) * (x))
#define DBL(x) ((x) + (x))
// 1. 매크로 함수를 만들때, 파라미터 영역과 치환 영역을
//    모두 괄호로 감싸주어야 합니다.
// => 우선순위 문제가 발생하지 않습니다.

// 2. 매크로 함수의 파라미터에서 변수의 값을 변경하는 부수효과를
//    피해야 합니다.
// => 미정의 동작의 위험성이 있습니다.

int main()
{
  int x = 1;

  // int result = SQUARE(++x);
  //            ++x * ++x   -> 미정의 동작

  ++x;
  int result = SQUARE(x);

  cout << result << endl;
}

#if 0
int main()
{
  int x = 10;

  int result = DBL(x + x) * DBL(x + x);
  //           (x + x) + (x + x) * (x + x) + (x + x)

  cout << SQUARE(x + x) << endl;
  //      x + x * x + x
}
#endif

#if 0
int main()
{
  cout << square(10) << endl;
  // cout << 10 * 10 << endl;

  cout << SQUARE(10) << endl;
}
#endif