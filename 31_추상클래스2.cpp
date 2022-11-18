// 31_추상클래스2.cpp
#include <iostream>
using namespace std;

// SRP(Single Responsibility Principle, 단일 책임 원칙)
// : 모든 클래스는 단 하나의 역활을 가져야 한다.

class Camera
{
public:
  void StartRecording() { cout << "Camera Recording Start" << endl; }
  void StopRecording() { cout << "Camera Recording Stop" << endl; }
};

class HDCamera
{
public:
  void StartRecording() { cout << "HDCamera Recording Start" << endl; }
  void StopRecording() { cout << "HDCamera Recording Stop" << endl; }
};
// OCP(Open Close Principle, 개방 폐쇄의 원칙)
// => 새로운 기능이 추가되어도 기존 코드는 수정되면 안된다.

class Car
{
  Camera *camera;

public:
  Car(Camera *camera)
      : camera(camera) {}

  void Go()
  {
    camera->StartRecording();
    cout << "Car Go" << endl;
    camera->StopRecording();
  }
};

int main()
{
  Camera camera;
  Car car(&camera);

  car.Go();
}