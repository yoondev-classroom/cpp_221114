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
//  => 전달되는 변수의 타입을 기반으로 함수가 호출됩니다.
//     "동일한 이름의 함수를 인자의 타입이 다르고, 개수가 다르다면 여러개 제공할 수 있습니다."
//     : 함수 오버로딩

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