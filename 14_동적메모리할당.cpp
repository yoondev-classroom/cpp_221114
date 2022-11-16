// 14_동적메모리할당.cpp
#include <cstdlib> // malloc, free
#include <iostream>
using namespace std;

// 1. malloc, 라이브러리의 함수 입니다.
//   => malloc은 인자로 메모리 크기를 전달 받습니다.
//   => void*를 반환하기 때문에, 명시적인 캐스팅이 필요합니다.

// 2. new 연산자 입니다.
//   => 타입을 전달합니다.
//   => 전달된 타입의 주소 타입을 반환합니다.
//      캐스팅이 필요하지 않습니다.

// 3. free는 함수입니다.
//   => 할당된 메모리의 주소를 전달받습니다.
//   => NULL을 전달할 경우, 아무일도 수행하지 않습니다.

// 4. delete 연산자 입니다.
//   => new를 통해 할당된 메모리의 주소를 전달받습니다.
//      NULL을 전달할 경우, 아무일도 수행하지 않습니다.
//   * 주의사항
//     연속된 메모리를 할당한 경우, new int[10]
//     반드시 delete[] 연산자로 해지해야 합니다.

#if 0
int main()
{
  int *p1 = static_cast<int *>(malloc(sizeof(int)));
  free(p1);

  int *p2 = static_cast<int *>(malloc(sizeof(int) * 10));
  free(p2);

  p1 = NULL;
  free(p1);

  int *pn1 = new int;
  delete pn1;

  int *pn2 = new int[10];
  // delete pn2; /* 미정의 동작 */
  delete[] p2; // 연속된 메모리 해지 연산자
}
#endif

// * malloc이 반환하는 메모리는 초기화되어 있지 않습니다.
//  => void *calloc(size_t count, size_t size);

#if 0
int main()
{
  int *p = static_cast<int *>(malloc(sizeof(int)));
  *p = 100;
  free(p);

  // p = static_cast<int *>(malloc(sizeof(int)));
  p = static_cast<int *>(calloc(1, sizeof(int)));
  cout << *p << endl;
}
#endif

// * new int 하였을 때, 초기화되지 않은 메모리를 반환합니다.
int main()
{
  int *p = new int;
  *p = 100;
  delete p;

  // 초기화 방법 => Direct initialization
  p = new int;
  cout << *p << endl; // 쓰레기값
  delete p;

  p = new int(); // 0
  cout << *p << endl;
  delete p;

  p = new int{}; // 0
  cout << *p << endl;
  delete p;

  p = new int(10); // 10
  cout << *p << endl;
  delete p;

  p = new int{10}; // 10
  cout << *p << endl;
  delete p;

  int *p2 = new int[5]{1, 2, 3, 4, 5};
  for (int i = 0; i < 5; ++i)
  {
    cout << p2[i] << endl;
  }
  delete[] p2;

  struct Point
  {
    int x;
    int y;
  };

  Point *p3 = new Point{10, 20};
  cout << p3->x << ", " << p3->y << endl;
  delete p3;
}