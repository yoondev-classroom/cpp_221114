// 36_예외.cpp
#include <iostream>
using namespace std;

// 1. C의 오류 처리
//  => 함수의 반환값
//    성공: 0  / 유효한 포인터
//    실패: -1 / nullptr

int OpenFile(const char *filename)
{
  if (filename == nullptr)
  {
    return -1;
  }

  return 0;
}

#include <stdlib.h> // atoi => strtol

// 2. 실패 가능한 함수를 사용할 경우, 반드시 오류를 확인해야 합니다.
// 3. 문제점
//  1. 반환되는 값이 실패인지 오류인지 모호할 수 있습니다.
//  2. 오류 처리를 강제할 수 없습니다.

int main()
{
  cout << atoi("x42") << endl;
  cout << atoi("0") << endl;

  int ret = OpenFile("hello.txt");
  if (ret != 0)
  {
    printf("실패\n");
  }
}