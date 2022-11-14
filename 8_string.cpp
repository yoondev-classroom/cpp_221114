// 8_string.cpp

#include <iostream>
using namespace std;

#include <cstring> // string.h
// 1. C 문자열
//   - string.h
//   - char[] / const char*

//  문제점
// 1) 문자열 연산에 대해서, 함수를 사용해야 합니다.
// 2) 사용자가 직접 메모리를 관리해야 합니다.
// 3) 문자열 연산을 수행할 때, 널문자 처리에 대해서 신경써야 합니다.
#if 0
int main()
{
  char str1[] = "hello";
  const char *str2 = "hello";

  // if (str1 == str2)
  if (strcmp(str1, str2) == 0)
  {
    cout << "동일한 문자열" << endl;
  }
  else
  {
    cout << "동일한 문자열 아닙니다." << endl;
  }

  char str3[32];
  strcpy(str3, str1);
  printf("%s\n", str3);

  strcat(str3, " world");
  printf("%s\n", str3);
}
#endif

#include <string>

// 2. C++ 문자열
int main()
{
  std::string s1 = "hello";
  std::string s2 = "hello";

  if (s1 == s2)
  {
    cout << "동일한 문자열" << endl;
  }

  std::string s3 = s1;
  cout << s3 << endl;

  s3 += " world";
  cout << s3 << endl;
}
