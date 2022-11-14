// test.cpp

// $ g++ test.cpp -c
// $ nm test.o

// C++에서는 함수의 정보에 파라미터 타입과 개수의 정보가 포함됩니다.
// => Name Mangling
/*
void foo() {}
  0000000000000000 T __Z3foov

void foo(int a) {}
  0000000000000000 T __Z3fooi

void foo(int a, int b, double c, char d) {}
  0000000000000020 T __Z3fooiidc
*/

void foo() {}
void foo(int a) {}
void foo(int a, int b, double c, char d) {}

// C에서 만든 함수를 C++에서 호출하거나,
// C++에서 만든 함수를 C에서 호출하는 방법

int main()
{
}