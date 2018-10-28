// This program illustrates how to use a sequential search in a program.

#include <iostream>

using namespace std;

const int ARRAY_SIZE = 10;

int seqSearch(const int list[], int listLength, int searchItem) {
  int loc;
  bool found = false;

  loc = 0;
  while (loc < listLength && !found) {
    if (list[loc] == searchItem) {
      found = true;
    } else {
      loc ++;
    }
  }
  if (found) {
    return loc;
  } else {
    return -1;
  }
}

int main() {
  int intList[ARRAY_SIZE];
  int number;

  cout << "Line 9: Enter " << ARRAY_SIZE << " integers." << endl;

  for (int index = 0; index < ARRAY_SIZE; index++) {
    cin >> intList[index];
  }

  cout << endl;
  cout << "Line 13: Enter the number to be searched: ";
  cin >> number;
  cout << endl;

  int pos = seqSearch(intList, ARRAY_SIZE, number);

  if (pos != -1) {
    cout << "Line 18: " << number << " is found at index " << pos << endl;
  } else {
    cout << "Line 20: " << number << " is not in the list." << endl;
  }
  return 0;
}
