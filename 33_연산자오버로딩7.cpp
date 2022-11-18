// 33_연산자오버로딩7.cpp
#include <iostream>
using namespace std;

class Image
{
public:
  Image() { cout << "Image 객체 생성" << endl; }
  ~Image() { cout << "Image 객체 파괴" << endl; }

  void Draw() const { cout << "Image Draw" << endl; }
};

// Ptr과 같이 포인터의 역활을 대신 하는 클래스 타입을 "스마트 포인터"라고 합니다.
template <typename T>
class Ptr
{
  T *obj;

public:
  Ptr(T *p = nullptr) : obj(p) {}
  ~Ptr() { delete obj; }

  T &operator*() { return *obj; }
  T *operator->() { return obj; }
};

#include <memory>
// 표준이 제공하는 스마트 포인터가 있습니다.
// 1) shared_ptr: 참조 계수
// 2) unique_ptr: 복사 금지 + 소유권 이동
int main()
{
  shared_ptr<Image> p1(new Image);
  p1->Draw();

  auto p3 = p1; /* 참조 계수 증가 */

  unique_ptr<Image> p2(new Image);
  p2->Draw();

  // auto p4 = p2;    /* 복사 금지 */
  auto p4 = move(p2); /* 소유권 이동 */
}

#if 0
int main()
{
  Ptr<Image> p(new Image);

  // Ptr p(new Image); // 컴파일러에 의해 T가 Image로 결정됩니다.
  // 생성자의 인자를 통한 T의 추론은 C++17부터 가능합니다.

  (*p).Draw();
  // Image& operator*()
  // Image&.Draw()

  p->Draw();
  // (p->)->Draw(); <- 컴파일러가 처리합니다.
  // Image* operator->()
}
#endif

#if 0
int main()
{
  Image *p = new Image;
  p->Draw();

  delete p; // 누락하면 메모리 누수의 위험성이 있습니다.
}
#endif