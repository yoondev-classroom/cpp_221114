// 37_STL2.cpp
#include <iostream>
#include <vector>
#include <list>
#include <array>
using namespace std;

// 1. 컨테이너
//  vector: 동적 배열, 연속된 메모리
//   array: 고정 배열, 연속된 메모리
//    list: 이중 연결 리스트, 연속된 메모리

//   map / unordered_map: 사전 자료 구조
//   set / unordered_set: 집합, 교집합, 합집합, 여집합

// 2. 컨테이너 특징
// 1) 템플릿 기반 입니다.
//  - 다양한 타입에서 사용할 수 있습니다.

// 2) 멤버 함수의 이름이 유사(동일)합니다.
// push_front     |-------------|    push_back
//  pop_front      insert/erase      pop_back
//      front                        back

// 3) vector는 push_front 연산을 제공하지 않습니다.
//    list는 임의 접근 연산자([])를 지원하지 않습니다.

// 4) 데이터를 제거하는 연산과, 참조하는 연산이 분리되어 있습니다.
//   => 참조를 반환하기 위해서입니다.

// #include <map> // 이진 트리
#include <unordered_map> // 해시 테이블 - C++11

int main()
{
  unordered_map<string, int> users;

  users["Tom"] = 42;
  users["Bob"] = 100;

  cout << users["Tom"] << endl;
}

#if 0
int main()
{
  vector<int> v = {10, 20, 30, 40};
  cout << v[0] << endl;
  cout << v[2] << endl;

  list<int> l = {10, 20, 30, 40};
  // cout << l[2] << endl;
}
#endif

#if 0
int main()
{
  // vector<int> v = {10, 20, 30, 40}; // C++11
  // array<int, 4> v = {10, 20, 30, 40};
  // list<int> v = {10, 20, 30, 40};

  vector<int> v = {10, 20, 30, 40};
  // push_front 같은 연산이 제공되지 않습니다.

  for (auto e : v)
  {
    cout << e << endl;
  }
}
#endif