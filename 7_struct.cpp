// 7_struct.cpp
#include <iostream>
using namespace std;

struct Point
{
  int x;
  double y;
  int z;
};

int main()
{
  Point pt = {10, 20};

  // int x = pt.x;
  // int y = pt.y;

  // C++17, Structured Binding Declration
  // 1) auto
  // 2) 개수가 동일해야 합니다.
  auto [x, y, z] = pt;
  cout << x << ", " << y << endl;

  // 3) 배열에서도 사용이 가능합니다.
  int arr[3] = {1, 2, 3};
  auto [a, b, c] = arr;

  cout << a << ", " << b << ", " << c << endl;
}