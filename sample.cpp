// sample.cpp
#include <iostream>
using namespace std;

#include "sample.h"

int main()
{
  int result = add(10, 20);
  cout << result << endl;
}

// $ g++ sample.cpp -c
// $ gcc add.c -c
// $ g++ sample.o add.o
/*
Undefined symbols for architecture x86_64:
  "add(int, int)", referenced from:
      _main in sample.o
     (found _add in add.o, declaration possibly missing extern "C")
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)

*/

/*
                 U __Z3addii
0000000000000000 T _main


                 U _add
0000000000000000 T _main

*/