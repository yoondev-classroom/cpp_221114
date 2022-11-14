// 2_namespace2.cpp

// namespace를 사용하는 방법.

// 1. 전체 이름을 사용하는 방법

#if 0
#include <iostream>

int main()
{
  std::cout << "Hello, C++" << std::endl;
}

#endif

// 2. using 선언(declartion)
#if 0
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  cout << "Hello, C++" << endl;
}
#endif

// 3. using 지시어(directive)
#include <iostream>
using namespace std;
// std 이름 공간안의 모든 요소를 암묵적으로 접근할 수 있습니다.

int main()
{
  cout << "Hello, C++" << endl;
}