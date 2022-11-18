// 36_예외2.cpp
#include <iostream>
using namespace std;

// 36_예외.cpp
#include <iostream>
using namespace std;

// 반환값 오류처리 문제점
//  1. 반환되는 값이 실패인지 오류인지 모호할 수 있습니다.
//  2. 오류 처리를 강제할 수 없습니다.

// C++은 오류 처리로 예외(Exception)를 사용할 수 있습니다.
//  1) 결과는 return하고, 오류는 throw 합니다.
//  2) 함수가 throw한 예외를 catch하지 않으면, 프로그램이 비정상종료 합니다.
//    try-catch

#if 0
int OpenFile(const char *filename)
{
  if (filename == nullptr)
  {
    throw -1;
  }

  return 0;
}

int main()
{
  // int ret = OpenFile("hello.txt");
  try
  {
    int ret = OpenFile(nullptr);
    printf("ret: %d\n", ret);
  }
  catch (int &e)
  {
    printf("error: %d\n", e);
  }

  printf("main end..\n");
}
#endif

// 1. C++은 예외의 종류에 따라서 사용자 정의 타입 예외를 정의합니다.
class InvalidFilenameException : public std::exception
{
public:
  // 2. std::exception의 what을 오버라이딩해서, 사용자 정의 오류 메세지를
  //   제공할 수 있습니다.
  const char *what() const noexcept override
  {
    return "Invalid file name";
  }
};
class OutOfMemoryException : public std::exception
{
};

int OpenFile(const char *filename)
{
  if (filename == nullptr)
  {
    // throw -1;
    throw InvalidFilenameException();
  }

  // ...
  throw OutOfMemoryException();

  return 0;
}

int main()
{
  // int ret = OpenFile("hello.txt");
  try
  {
    int ret = OpenFile(nullptr);
    printf("ret: %d\n", ret);
  }
  catch (OutOfMemoryException &e)
  {
  }
  catch (InvalidFilenameException &e)
  {
    cout << e.what() << endl;
  }

  printf("main end..\n");
}