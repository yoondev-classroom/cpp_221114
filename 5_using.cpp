// 5_using.cpp
#include <iostream>
using namespace std;

// using
// 1. namespace
//   - using 선언
//     using std::cout;
//     using std::cin;

//   - using 지시어
//     using namespace std;

// 2. C++11, 기존 타입의 별칭을 만들 때 사용할 수 있습니다.
//   => typedef를 대체합니다.
//   1) 복잡한 타입 표현식을 표현할 때, 직관적이지 않습니다.
//   2) 템플릿 타입 별칭을 만들 수 없습니다.

typedef int ARR3[3];

int *foo()
{
  // static int x[3];
  static ARR3 x;

  return x; // &x[0];
}

// int (*goo())[3]

// 1. goo()
// - goo는 함수 입니다. 함수의 반환타입은?

// 2. (*goo())
// - 함수의 반환타입은 포인터 입니다. 어떤 주소를 가르키는가?

// 3. (*goo())[3]
// - 3개짜리 배열의 주소를 가르킵니다. 배열의 각 요소는?

// 4. int (*goo())[3]
// - 배열의 각 요소는 int 입니다.

#if 0
typedef int (*PARR3)[3];

// int (*goo())[3]
// ARR3 *goo()

PARR3 goo()
{
  static int x[3];
  return &x; // int(*)[3]
}

int main()
{
  int n;
  // n의 타입은 int 입니다.
  // => 식별자(n)를 제외한 나머지가 타입입니다.

  int x[3] = {10, 20, 30};
  // x의 타입은 무엇인가요?
  // => int[3]

  // 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석된다.
  // => Decay
  // 예외
  //   1) sizeof
  printf("%zu\n", sizeof(x));
  printf("%zu\n", sizeof(int[3]));

  int *p = x; // &x[0];
  printf("%zu\n", sizeof(p));
  printf("%zu\n", sizeof(&x[0]));

  //  2) &
  int(*p2)[3] = &x; // x -> Decay X -> int[3]
  // 배열 포인터
}
#endif

// typedef int (*PARR3)[3];
using PARR3 = int (*)[3];

PARR3 goo()
{
  static int x[3];
  return &x; // int(*)[3]
}

int add(int a, int b) { return a + b; }
// int (*)(int, int) -----> add: int(int, int)

// typedef int (*FP)(int, int);
using FP = int (*)(int, int);

int main()
{
  // int (*fp)(int, int);
  FP fp;

  // C++에서는 아래처럼 사용하는 것이 좋습니다.
  fp = &add;
  int result = (*fp)(10, 20);
  cout << result << endl;

  // C 에서는 아래 표현이 선호됩니다.
  fp = add;            // 함수의 이름은 함수 포인터로 해석됩니다.
  result = fp(10, 20); // 함수 포인터에 대한 호출은 참조로 해석됩니다.
  cout << result << endl;
}