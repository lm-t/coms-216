//Selection sort

#include <iostream>

using namespace std;

void selectionSort(int list[], int length) {
  int index;
  int smallestIndex;
  int location;
  int temp;

  for (size_t index = 0; index < length - 1; index++) {
    //Step a
    smallestIndex = index;
    for (size_t location = index + 1; location < length; location++) {
      if (list[location] < list[smallestIndex]) {
        smallestIndex = location;
      }
    }
    //Step b
    temp = list[smallestIndex];
    list[smallestIndex] = list[index];
    list[index] = temp;
  }
}

int main() {
  int list[] = {2, 56, 34, 25, 73, 46, 89, 10, 5, 16};
  int i;

  selectionSort(list, 10);

  cout << "After sorting, the list elements are:" << endl;

  for (size_t i = 0; i < 10; i++) {
    cout << list[i] << " ";
  }
  cout << endl;

  return 0;
}
