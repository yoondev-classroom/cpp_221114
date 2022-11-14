
// 인라인 함수로 대체할 수 없는 매크로 함수의 용도

// 1.
#if 0
#include <stdio.h>

enum Color
{
  Color_Red,
  Color_Green,
  Color_Blue,
};

struct color
{
  Color color;
  const char *name;
};

// 1. ##, #의 기능을 활용한 매크로 함수
#define COLOR(color)      \
  {                       \
    Color_##color, #color \
  }

int main()
{
#if 0
  color colors[3] = {
      {Color_Red, "Red"},
      {Color_Green, "Green"},
      {Color_Blue, "Blue"},
  };
#endif
  color colors[3] = {
      COLOR(Red),
      COLOR(Green),
      COLOR(Blue)};
}
#endif

// __VA_ARGS__: Variadic Macro - C99

// 2. 조건부 컴파일
// $ gcc 0_QA.cpp -DNDEBUG
#include <stdio.h>

#ifndef NDEBUG
#define TRACE(fmt, ...) fprintf(stderr, "[%s:%d]: " fmt, __func__, __LINE__, __VA_ARGS__)
#else
#define TRACE(fmt, ...) (void)0
#endif

int foo() { return 42; }

int main()
{
  (void)foo();
  // 반환값을 무시하겠다.

  int a = 10;
  TRACE("a: %d\n", a);
}