// 29_다형성3.cpp
#include <iostream>
using namespace std;
#include <list>   // 이중 연결 리스트 컨테이너
#include <vector> // 연속된 메모리 자료구조(컨테이너)

#if 0
class Dog
{
};
class Cat
{
};

class Rabbit
{
};

int main()
{
  vector<Dog *> dogs;
  dogs.push_back(new Dog);
  dogs.push_back(new Dog);
  dogs.push_back(new Dog);

  vector<Cat *> cats;
  cats.push_back(new Cat);
  cats.push_back(new Cat);
  cats.push_back(new Cat);

  vector<Rabbit *> rabbits;
  rabbits.push_back(new Rabbit);
}
#endif

// 활용 2. 동종을 보관하는 컨테이너
//  => Animal의 자식 클래스는 같은 컨테이너 묶어서 관리할 수 있습니다.

class Animal
{
};

class Dog : public Animal
{
};
class Cat : public Animal
{
};
class Rabbit : public Animal
{
};

int main()
{
  vector<Animal *> animals;

  animals.push_back(new Dog);
  animals.push_back(new Cat);

  animals.push_back(new Rabbit);

  //-----
  list<int> v; // 순회 가능한 컨테이너
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);

  for (auto e : v)
  {
    cout << e << endl;
  }
}