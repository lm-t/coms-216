#include <iostream>
#include <string>

using namespace std;

class baseClass {
public:
  void print() const;

  baseClass(string s = " ", int a = 0);
  //Postcondition: str = s; x = a;

protected:
  int x;

private:
  string str;
};

class derivedClass: public baseClass {
public:
  void print() const;

  derivedClass(string s = "", int a  = 0, int b = 0);
  //Postcondition: str = s; x = a; y = b;

private:
  int y;
};

int main() {
  baseClass baseObject("This is the base class", 2);
  derivedClass derivedObject("DDDDDD", 3, 7);

  baseObject.print();
  derivedObject.print();

  return 0;
}

void baseClass::print() const {
  cout << x << " " << str << endl;
}

baseClass::baseClass(string s, int a) {
  str = s;
  x = a;
}

void derivedClass::print() const {
  cout << "Derived class: " << y << endl;
  baseClass::print();
}

derivedClass::derivedClass(string s, int a, int b) : baseClass("Hello Base", a + b) {
  y = b;
}
