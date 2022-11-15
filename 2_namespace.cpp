// 2_namespace.cpp
#include <iostream>

// 1. C 에서는 이름 충돌을 방지하기 위해서 다른 이름을 사용해야 합니다.
// => 접두어를 약속하는 경우가 많습니다.
//    audio_init() / video_init()
// => C++은 이름 공간(namespace)의 문법을 이용해서, 이름 충돌을 해결할 수 있습니다.

// 2. namespace
//  1) 이름 충돌을 방지하기 위해 사용합니다.
//  2) C++ 표준의 모든 요소는 std 이름 공간안에 존재합니다.
//  3) 프로그램의 각 요소를 관련된 요소끼리 그룹화할 수 있습니다.

// audio.cpp
namespace audio // namespace는 소문자로 작성합니다.
{
  void init()
  {
    std::cout << "audio init" << std::endl;
  }

  int count = 0;
}

// audio_play.cpp
namespace audio
{
  void play() {}
}

// video.cpp
namespace video
{
  void init()
  {
    std::cout << "video init" << std::endl;
  }

  int count = 0;
}

int main()
{
  audio::init();
  video::init();

  std::cout << audio::count << std::endl;

  video::count = 10;
  std::cout << video::count << std::endl;
}