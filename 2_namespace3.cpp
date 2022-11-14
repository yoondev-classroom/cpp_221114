// 2_namespace3.cpp

#include <iostream>

// string.h  => cstring
//  ctype.h  => cctype
// stdlib.h  => cstdlib

// #include <stdio.h>
#include <cstdio>
// 1. C++ 표준 헤더는 확장자가 없는 경우가 많습니다.
// 2. C의 모든 표준 함수를 std 이름 공간안에서 사용할 수 있습니다.

int main()
{
  int n;

  std::printf("Hello, C\n");

  std::scanf("%d", &n);
}