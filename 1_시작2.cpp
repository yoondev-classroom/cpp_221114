// 1_시작2.cpp

// 1. C++ 확장자
//   .cpp / .cc / .cxx

// 2. C++ 컴파일러
//  - Windows, Microsoft Visual C/C++ Compiler => MSVC
//    cl.exe
//  - Linux, GNU C/C++ Compiler => GCC
//    gcc / g++ / cc / c++
//  - Apple, LLVM
//    gcc / g++ / c++ / c++ / clang / clang++

// 3. C 표준 / C++ 표준
//   C: c89/c90
//      c99      - *
//      c11

// C++: C++98/03 => 1.0
//      C++11/14 => Modern C++
//      C++17/20

// 4. C++은 C를 지원합니다.
//   "C의 표준과 C++ 내의 C의 표준은 다릅니다."

#if 0
#include <stdio.h>

int main(void)
{
  printf("Hello, C2\n");
  return 0;
}
#endif

#if 0
#include <cstdio>
// C++은 헤더파일의 확장자가 없는 경우가 있습니다.

void foo(void) {}
void goo() {}

int main()
{
  printf("Hello, C++\n");

  // foo(10, 20); // 컴파일 오류!
  // goo(10, 20); // 컴파일 오류!

  // return 0;
  //  : 컴파일러가 자동으로 return 0; 추가해줍니다.
}
#endif

// C++ 표준 입출력 라이브러리가 있습니다.
#include <iostream>

// std::cout : 표준 출력
// std::cin  : 표준 입력
// std::cerr : 표준 에러

// std::endl : New line

int main()
{
  std::cout << "Hello, C++" << std::endl;
}