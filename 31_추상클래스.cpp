// 31_추상클래스.cpp
#include <iostream>
using namespace std;

// 추상 클래스
//  : 순수 가상 함수를 1개 이상 가지고 있는 클래스입니다.
//  "인스턴스화(객체 생성)가 불가능합니다."
class Shape
{
public:
  virtual ~Shape() {}

  // 부모의 입장에서 구현을 제공할 필요가 없고,
  // 자식 클래스 입장에서는 반드시 Draw()를 오버라이딩 해야 합니다.
  // => 순수 가상 함수(pure virtual function)

  virtual void Draw() const = 0;

  // virtual void Draw() const { cout << "Shape Draw" << endl; }
};

// 부모가 제공하는 순수 가상 함수의 오버라이딩을 하지 않으면,
// 자식 클래스도 추상 클래스가 되어 인스턴스화가 불가능합니다.
class Rect : public Shape
{
public:
  void Draw() const override { cout << "Rect Draw" << endl; }
};

int main()
{
  // Shape s;
  Rect r;
}