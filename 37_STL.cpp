// 37_STL.cpp
#include <iostream>
using namespace std;

// Standard Template Library
// - 1979년: C++ 탄생
// - 1990년: C++ 표준 위원회 설립
// - 1998년: C++ 1차 표준안 => 표준 라이브러리, STL

// STL 구성 요소
// 1. 컨테이너: 데이터를 저장하기 위한 자료구조
// 2. 알고리즘: 컨테이너의 요소를 검색,정렬 등의 일반 함수
// 3. 반복자: 컨테이너의 요소를 열거하기 위해, 포인터와 비슷하게 동작하는
//          객체

#include <string>
#include <complex>

int main()
{
  string s1 = "hello";
  string s2 = s1 + s1; // 연산자 재정의
  cout << s1 << endl;
  cout << s2 << endl;

  complex<int> c1(10, 5); // 10 + 5i
  complex<int> c2(2, 3);  // 2 + 3i
  complex<int> result = c1 + c2;

  cout << result.real() << ", " << result.imag() << endl;
  cout << result << endl;
}