// 3_iostream.cpp
#include <iostream>
// Input Ouput Stream
// - 표준 출력: cout
// - 표준 입력: cin

using namespace std;

#if 0
int main()
{
  int age;
  printf("age: ");

  scanf("%d", &age);
  printf("age: %d\n", age);
}
#endif

int main()
{
  int age;
  cout << "age: ";

  cin >> age;
  cout << "age: " << age << endl;
}