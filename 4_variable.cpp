// 4_variable.cpp

#include <iostream>
using namespace std;

#if 0
// 사용자 정의 타입
// struct Point
//        ----- Tag
struct Point
{
  int x;
  int y;
};
typedef struct Point POINT;

union Sample
{
  int a;
  double b;
};

enum State
{
  TASK_RUNNING,
  TASK_STOPPED
};

int main()
{
  struct Point pt;
  POINT pt2;

  union Sample s;
  enum State s2;
}
#endif

// 1. C++은 태그를 타입으로 인식합니다.
//   struct / union / enum 을 생략할 수 있습니다.

// 2. C++11에서는 멤버 데이터 변수의 초기값을 지정할 수 있습니다.

struct Point
{
  int x = 0;
  int y = 0;
};

union Sample
{
  int a;
  double b;
};

enum State
{
  TASK_RUNNING,
  TASK_STOPPED
};

int main()
{
  // Point pt = {10, 20};
  Point pt;
  cout << pt.x << ", " << pt.y << endl;

  Sample s1;
  State s2;
}