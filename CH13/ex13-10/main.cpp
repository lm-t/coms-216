//This program shows how to use the class template listType.

#include <iostream>

#include "myString.h"
#include "listType.h"

using namespace std;

int main() {
  listType<int> intList(100);
  listType<newString> stringList;
  int index;
  int number;

  cout << "List 5: Processing the integer list" << endl;
  cout << "List 6: Enter 5 integers: ";

  for (size_t index = 0; index < 5; index++) {
    cin >> number;
    intList.insertAt(number, index);
  }

  cout << endl;
  cout << "List 11: intList: ";
  intList.print();
  cout << endl;

  //Sort intList
  intList.sort();

  cout << "Line 15: After sorting, intList: ";
  intList.print();
  cout << endl;

  newString str;

  cout << "Line 19: Processing the string list" << endl;

  cout << "line 20: Enter 5 strings: ";

  for (size_t index = 0; index < 5; index++) {
    cin >> str;
    stringList.insertAt(str, index);
  }

  cout << endl;
  cout << "Line 25: stringList: ";
  stringList.print();
  cout << endl;

  //Sort stringList
  stringList.sort();

  cout << "Line 29: After sorting, stringList: ";
  stringList.print();
  cout << endl;

  int intListSize;

  cout << "Line 33: Enter the size of the integer list: ";
  cin >> intListSize;
  cout << endl;

  listType<int> intList2(intListSize);

  cout << "Line 37: Processing the integer list" << endl;
  cout << "Line 38: Enter " << intListSize << " integers: ";

  for (size_t index = 0; index < intListSize; index++) {
    cin >> number;
    intList2.insertAt(number, index);
  }

  cout << endl;

  cout << "Line 43: intList2: ";
  intList2.print();
  cout << endl;

  //Sort intList2
  intList2.sort();

  cout << "Line 47: After sorting, intList2: ";
  intList2.print();
  cout << endl;

  cout << "Line 50: Length of intList2: " << intList2.getLength() << endl;
  cout << "Line 51: Maximum size of intList2: " << intList2.getMaxSize() << endl;

  return 0;
}
