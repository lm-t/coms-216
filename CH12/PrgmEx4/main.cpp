#include "largeIntegers.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  //Testing largeIntegers class
  string s1 = "43667";
  string s2 = "289";

  largeIntegers *a = new largeIntegers(s1);
  largeIntegers *b = new largeIntegers(s2);

  a -> print();
  b -> print();

  a -> subtract(b);
  a -> print();
  return 0;
}
