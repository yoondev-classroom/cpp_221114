// 22_복사생성자4.cpp
#include <iostream>
using namespace std;

class Sample
{
public:
  Sample() {}
  Sample(const Sample &rhs) { cout << "Sample(const&)" << endl; }
  ~Sample() { cout << "~Sample()" << endl; }
};

int main()
{
}