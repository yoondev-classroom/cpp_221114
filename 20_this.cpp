// 20_this.cpp
#include <iostream>
using namespace std;

#if 0
struct Point
{
  int x;
  int y;
};

void Set(Point *pt, int x, int y)
{
  pt->x = x;
  pt->y = y;
}

int main()
{
  Point pt = {10, 20};

  Set(&pt, 30, 40);

  cout << pt.x << endl;
  cout << pt.y << endl;
}
#endif

#if 0
struct Point
{
  int x;
  int y;

  // this는 멤버 함수 내부에서 사용할 수 있는 전달 받은 객체의 주소를
  // 의미합니다.

  // void Point::Set(Point *const this, int ax, int ay) => thiscall
  void Set(int ax, int ay)
  {
    this->x = ax;
    this->y = ay;
    // x = ax;
    // y = ay;
  }
};

int main()
{
  Point pt1, pt2;

  pt1.Set(10, 20);
  pt2.Set(20, 30);
}
#endif

#if 0

int main()
{
  Point pt = {10, 20};

  pt.Set(30, 40);

  cout << pt.x << endl;
  cout << pt.y << endl;
}
#endif

void Set(int a, int b)
{
}

class Sample
{
  int x;

public:
  // void Sample::Set(Sample* this, int a, int b)
  void Set(int a, int b)
  {
    this->x = a + b;
    // this->x = a + b;
  }
  /*
void Sample::Set(int,int) PROC                   ; Sample::Set, COMDAT
        mov     DWORD PTR [rsp+24], r8d          // b = 200
        mov     DWORD PTR [rsp+16], edx          // a = 100
        mov     QWORD PTR [rsp+8], rcx           // this = &s
        mov     eax, DWORD PTR b$[rsp]           // eax = b
        mov     ecx, DWORD PTR a$[rsp]           // ecx = a
        add     ecx, eax                         // ecx += eax
        mov     eax, ecx                         // eax = ecx
        mov     rcx, QWORD PTR this$[rsp]        // rcx = this;
        mov     DWORD PTR [rcx], eax             // this->x = eax;
        ret     0
void Sample::Set(int,int) ENDP                   ; Sample::Set
  */
};

int main()
{
  Sample s;
  s.Set(100, 200); // => Set(&s, 100, 200)
  /*
    mov     r8d, 200                      ; r8d = 200
    mov     edx, 100                      ; edx = 100
    lea     rcx, QWORD PTR s$[rsp]        ; rcx = &s
    call    void Sample::Set(int,int)              ; Sample::Set

  */

  Set(100, 200);
  /*
    mov     edx, 200                      ; 000000c8H
    mov     ecx, 100                      ; 00000064H
    call    void Set(int,int)
  */
}