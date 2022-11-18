// 31_추상클래스3.cpp
#include <iostream>
using namespace std;

// 문제의 원인
//  강한 결합
// Car -------<> Camera

// => 약한 결합(느슨한 결합)을 사용하면 교체 가능한 설계를 구현할 수 있습니다.

// Car ------<> <<BlackBox>>
//                    |
//                 ---------
//                 |       |
//              Camera  HDCamera

//  핵심: 인터페이스를 기반으로 느슨한 결합의 코드를 작성하는 것은
//       OCP를 만족합니다.
//      "교체 가능한 유연한 설계"
//      DIP(Dependency Inversion Principle, 의존 관계 역전 원칙)
//       : 클래스는 구체적인 타입에 의존하는 것이 아니라,
//         추상 타입(추상 클래스/인터페이스)에 의존해야 한다.
//    => 정책을 변경할 수 있습니다.
//       "전략 패턴(Sterategy Pattern)"

// 1. 카메라의 설계자와 자동차의 설계자는 인터페이스(프로토콜)를 약속합니다.

// 인터페이스 / 프로토콜
struct BlackBox
{
  virtual ~BlackBox() {}

  virtual void StartRecording() = 0;
  virtual void StopRecording() = 0;
};

// 2. 자동차의 제작자는 BlackBox 인터페이스를 이용해서 코드를 작성합니다.
class Car
{
  BlackBox *camera;

public:
  Car(BlackBox *camera)
      : camera(camera) {}

  void Go()
  {
    camera->StartRecording();
    cout << "Car Go" << endl;
    camera->StopRecording();
  }
};

// 3. 모든 카메라의 제작자는 BlackBox의 인터페이스를 기반으로
//    제작되어야 합니다.

//  "인터페이스를 상속한다" 라고 하지 않고, "인터페이스를 구현한다." 라고 합니다.
//  Java
//   class Camera extends BlackBox    => 상속
//   class Camera implements BlackBox => 인터페이스 구현
class Camera : public BlackBox
{
public:
  void StartRecording() override
  {
    cout << "Camera Recording Start" << endl;
  }
  void StopRecording() override
  {
    cout << "Camera Recording Stop" << endl;
  }
};

class HDCamera : public BlackBox
{
public:
  void StartRecording() override
  {
    cout << "HDCamera Recording Start" << endl;
  }
  void StopRecording() override
  {
    cout << "HDCamera Recording Stop" << endl;
  }
};

int main()
{
  HDCamera camera;
  Car car(&camera);

  car.Go();
}

// Design Pattern
//  => 디자인 패턴을 적용하는 두가지 방법
// 1) 변화를 예상하고, 처음부터 패턴을 통해 구조를 설계하는 방법 => 오버 디자인
// 2) 기존 코드를 리팩토링을 통해 패턴을 적용하는 방법
