//Bubble Sort - Ex. 16-1

#include <iostream>

using namespace std;

void bubbleSort(int list[], int length);

int main() {
  int list[] = {2, 56, 34, 25, 73, 46, 89, 10, 5, 16}; //Line 1
  int i; //Line 2

  bubbleSort(list, 10); //Line 3

  cout << "After sorting, the list elements are:" << endl; //Line 4

  for (size_t i = 0; i < 10; i++) { //Line 5
    cout << list[i] << " "; //Line 6
  }
  cout << endl; //Line 7

  return 0; //Line 8
}

//bubbleSort definition
void bubbleSort(int list[], int length) {
  int temp;
  int iteration;
  int index;
  for (size_t iteration = 1; iteration < length; iteration++) {
    for (size_t index = 0; index < length - iteration; index++) {
      if (list[index] > list[index + 1]) {
        temp = list[index];
        list[index] = list[index + 1];
        list[index + 1] = temp;
      }
    }
  }
}
