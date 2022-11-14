// 2_namespace2.cpp
#include <iostream>

// namespace를 사용하는 방법.

namespace audio
{
  void init() { std::cout << "audio init" << std::endl; }
}

namespace video
{
  void init() { std::cout << "video init" << std::endl; }
}

// 1. 전체 이름을 사용하는 방법
#if 0
int main()
{
  audio::init();
  video::init();

  std::cout << "Hello, C++" << std::endl;
}

#endif

// 2. using 선언(declartion)
#if 0
using std::cout;
using std::endl;

using audio::init;
// using video::init;

int main()
{
  init();
  video::init();

  cout << "Hello, C++" << endl;
}
#endif

#if 1
// 3. using 지시어(directive)

using namespace std;
// std 이름 공간안의 모든 요소를 암묵적으로 접근할 수 있습니다.

// > 현업에서 사용하면 안됩니다.
//  => 이름 충돌의 문제가 발생할 수 있습니다.

using namespace audio;
using namespace video;

int main()
{
  // init();

  cout << "Hello, C++" << endl;
}
#endif