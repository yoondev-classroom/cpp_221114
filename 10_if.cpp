// 10_if.cpp

#include <iostream>
using namespace std;

// 성공시 0, 실패시 0이 아닌 값
int OpenFile(const char *filename) { return 1; }

// 성공시 유효한 메모리, 실패시 NULL
int *AllocMemory(size_t size) { return NULL; }

enum TaskState
{
  TASK_RUNNING,
  TASK_STOPPED,
};

TaskState GetCurrentState() { return TASK_RUNNING; }

int main()
{
  for (int i = 0; i < 10; ++i)
  {
  }

  // C++17, if-statement with initializer
  if (int ret = OpenFile("a.txt"); ret != 0)
  {
    cout << "file open error" << endl;
  }

  if (int *ret = AllocMemory(42); ret == NULL)
  {
    cout << "memory alloc error" << endl;
  }

  // Switch 문에서도 사용이 가능합니다.
  switch (TaskState state = GetCurrentState(); state)
  {
  case TASK_RUNNING:
    break;

  case TASK_STOPPED:
    break;

  default:
    break;
  }

  switch (TaskState state = GetCurrentState(); state)
  {
  case TASK_RUNNING:
    break;

  case TASK_STOPPED:
    break;

  default:
    break;
  }
}

#if 0
int main()
{
  for (int i = 0; i < 10; ++i)
  {
  }

  int ret1 = OpenFile("a.txt");
  if (ret1 != 0)
  {
    cout << "file open error" << endl;
  }

  int *ret2 = AllocMemory(42);
  if (ret2 == NULL)
  {
    cout << "memory alloc error" << endl;
  }
}
#endif