// 12_레퍼런스2.cpp

#include <iostream>
using namespace std;

// Call by value
//  => 값에 의한 호출
void inc1(int n) { ++n; }

// Call by pointer
//  => 포인터에 의한 호출(주소를 전달합니다.)
void inc2(int *p) { ++(*p); }

// Call by reference
//  => 참조를 전달합니다.
void inc3(int &r) { ++r; }

int main()
{
  int x;

  x = 10;
  inc1(x);
  cout << x << endl; // 10

  x = 10;
  inc2(&x);
  cout << x << endl; // 11

  x = 10;
  inc3(x);
  cout << x << endl; // 11
}