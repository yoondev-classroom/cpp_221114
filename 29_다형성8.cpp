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
//    => "다형성"

// 4. 자식이 재정의(오버라이딩)하는 모든 함수는 반드시 "가상함수"이어야 한다.
// 5. 부모 클래스의 소멸자는 반드시 가상이어야 한다.
//    => 가상 소멸자

// 6. OCP(Open Close Principle, 개방 폐쇄 원칙)
//   : 확장에는 열려 있고, 수정에는 닫혀 있어야 합니다.
//   => "새로운 기능이 추가되어도 기존 코드는 수정되면 안된다."

// 7. 상속은 재사용이 아닌, 다형성을 목적으로 사용해야 합니다.
//   => Upcasting, Overriding, virtual

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

class Triangle : public Shape
{
public:
  void Draw() const override { cout << "Triangle Draw" << endl; }
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
    else if (cmd == 3)
    {
      shapes.push_back(new Triangle);
    }
    else if (cmd == 9)
    {
      for (auto e : shapes)
      {
        e->Draw();
        // e의 실제 객체 타입에 따라서 각 클래스의 함수가 호출됩니다.
        // Draw() ----> Rect::Draw()
        //              Circle::Draw()
        //              Triangle::Draw()
        // - 다형성(Polymorphism)
        //  "OCP를 만족합니다."
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

// Linux, Unix
//  => 모든 것은 File 입니다.
//  => VFS(Virtual File System)
//  read / write => File    => 하드 디스크 read / write
//                  Device  => 디바이스 제어
//                  Socket  => 네트워크 패킷 read / write
