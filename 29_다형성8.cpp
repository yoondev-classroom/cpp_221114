// 29_다형성8.cpp
#include <iostream>
#include <vector>
using namespace std;

// 1. 각 도형을 클래스로 설계합니다.

// 2. 부모 클래스를 도입합니다.
//  => 하나의 컨테이너에 모든 도형을 보관할 수 있습니다.
//   "연관된 클래스는 묶어서 관리할 수 있습니다."
//    : 동종을 보관하는 컨테이너

// 3. 자식 클래스의 공통의 기능을 부모의 포인터(참조)타입을 통해 이용하기 위해서는
//    반드시 해당 기능이 부모를 통해서 제공되어야 합니다.
//    그래야지만 해당 기능을 부모의 포인터로 이용할 수 있습니다.

//    => LSP(Liskov Substitution Principle, 리스코프 대체 원칙)
//      - 자식은 부모 클래스로 대체할 수 있어야 한다.
//      "자식의 공통의 기능이 부모로부터 비롯되어야 한다."

// 4. 자식이 재정의(오버라이딩)하는 모든 함수는 반드시 "가상함수"이어야 한다.
// 5. 부모 클래스의 소멸자는 반드시 가상이어야 한다.
//    => 가상 소멸자

class Shape
{
public:
  virtual ~Shape() {}

  virtual void Draw() const { cout << "Shape Draw" << endl; }
};

class Rect : public Shape
{
public:
  ~Rect() override { cout << "~Rect()" << endl; }
  void Draw() const override { cout << "Rect Draw" << endl; }
};

class Circle : public Shape
{
public:
  void Draw() const override { cout << "Circle Draw" << endl; }
};

int main()
{
  // vector<Rect *> rects;
  // vector<Circle *> circles;

  vector<Shape *> shapes;

  while (1)
  {
    int cmd;
    cin >> cmd;

    if (cmd == 1)
    {
      shapes.push_back(new Rect);
    }
    else if (cmd == 2)
    {
      shapes.push_back(new Circle);
    }
    else if (cmd == 9)
    {
      for (auto e : shapes)
      {
        e->Draw();
      }
    }
    else if (cmd == 0)
    {
      for (auto e : shapes)
      {
        delete e;
      }
      break;
    }
  }
}