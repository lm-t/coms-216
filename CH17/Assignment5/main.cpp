#include <iostream>
#include "orderedLinkedList.h"

using namespace std;

int main() {
  //Test code
  orderedLinkedList<int> list;
  int num;

  cout << "Enter numbers (use any character to stop):" << endl;
  while (cin >> num) {
    list.insert(num);
  }

  cout << "ordered list: ";
  list.print();
  cout << endl;

  cout << "reversed list: ";
  list.printListReverse();

  return 0;
}
