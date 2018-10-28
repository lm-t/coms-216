//Chapter 16 Exercise 22

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> intList(10);

  for (int i = 0; i < 10; i++) {
    intList[i] = 2 * i + 5;
  }
  cout << intList.front() << " " << intList.back() << endl;
}

//Output: 5 23
