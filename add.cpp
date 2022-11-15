// add.cpp
#include <iostream>

#include "sample.h"

// const int c = 100;
// 다른 파일에서 접근이 불가능합니다.

extern const int c = 100;

int add(int a, int b)
{
  std::cout << "C++" << std::endl;
  return a + b;
}