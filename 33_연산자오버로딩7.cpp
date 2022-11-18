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
class Ptr
{
  Image *obj;

public:
  Ptr(Image *p = nullptr) : obj(p) {}
  ~Ptr() { delete obj; }

  Image &operator*() { return *obj; }
  Image *operator->() { return obj; }
};

int main()
{
  Ptr p = new Image;

  (*p).Draw();
  // Image& operator*()
  // Image&.Draw()

  p->Draw();
  // (p->)->Draw(); <- 컴파일러가 처리합니다.
  // Image* operator->()
}

#if 0
int main()
{
  Image *p = new Image;
  p->Draw();

  delete p; // 누락하면 메모리 누수의 위험성이 있습니다.
}
#endif