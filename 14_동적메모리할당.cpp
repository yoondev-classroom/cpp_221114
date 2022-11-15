// 14_동적메모리할당.cpp
#include <cstdlib> // malloc, free
#include <iostream>

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

int main()
{
  int *p1 = static_cast<int *>(malloc(sizeof(int)));
  free(p1);

  p1 = NULL;
  free(p1);

  int *pn1 = new int;
  delete pn1;
}