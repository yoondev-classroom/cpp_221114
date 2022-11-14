// 3_iostream.cpp
#include <iostream>
// Input Ouput Stream
// - 표준 출력: cout
// - 표준 입력: cin

using namespace std;

#if 0
int main()
{
  double age;
  printf("age: ");

  scanf("%lf", &age);
  printf("age: %lf\n", age);
}
#endif

// 1. 서식을 지정하지 않고도, 각 타입에 따른 입력/출력이 제대로 처리됩니다.
// 2. 주소를 전달하지 않아도, 변수의 값이 변경됩니다.
// 3. std::cout / std::cin / std::endl 정체는 무엇인가?

#if 1
int main()
{
  double age;
  cout << "age: ";

  cin >> age;
  cout << "age: " << age << endl;
}
#endif