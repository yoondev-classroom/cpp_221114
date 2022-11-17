// 24_객체복사6.cpp
#include <iostream>
#include <string>
using namespace std;

// 1. 참조 계수 => 소유권 공유: std::shared_ptr
// 2. 복사 금지 => 소유권 독점: std::unique_ptr

#include <memory>
// shared_ptr / unique_ptr

class Resource
{
public:
  Resource() { cout << "생성" << endl; }
  ~Resource() { cout << "파괴" << endl; }
};

int main()
{
  unique_ptr<Resource> p1(new Resource); // p1 ----> R
  cout << p1 << endl;

  cout << "--------" << endl;

  unique_ptr<Resource> p2(std::move(p1)); // p1 = null, p2 ----> R
  cout << p1 << endl;
  cout << p2 << endl;
}

#if 0
int main()
{
  shared_ptr<Resource> p1(new Resource); // ref: 1
  shared_ptr<Resource> p2 = p1;          // ref: 2

  p2 = nullptr; // ref: 1

  cout << "----------" << endl;
  p1 = nullptr; // ref: 0 -> Resource 파괴
  cout << "----------" << endl;
}
#endif

#if 0
int main()
{
  string s1 = "hello";
  string s2 = "world";

  // string s3 = s1; // copy
  string s3 = std::move(s1);
  cout << s1 << endl;
  cout << s3 << endl;
}
#endif