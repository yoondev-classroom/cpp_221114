// 3_iostream2.cpp
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
  // int n = 0xFAFA;
  // 1111 1010 1111 1010

  // C++11 부터 2진수 상수를 만들 수 있습니다.
  // => 싱글 따옴표를 이용해서, 가독성을 높일 수 있습니다.
  int n = 0b1111'1010'1111'1010;

  printf("%x\n", n);
  printf("%d\n", n);
  printf("%X\n", n);

  printf("%10d\n", n);
  printf("%010d\n", n);

  // IO 조정자 / 조작자(manipulator)
  cout << hex << n << endl;
  cout << dec << n << endl;
  cout << hex << uppercase << n << endl;

  // iomanip 헤더의 포함이 필요합니다.
  cout << dec << setw(10) << n << endl;
  cout << dec << setw(10) << setfill('0') << n << endl;
}