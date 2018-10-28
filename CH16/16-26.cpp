//Chapter 16 Exercise 26

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> intList(5);

  int x = 0;

  for (auto &p : intList) {
    if (x % 2 == 0) {
      p = x * (x + 2);
    } else {
      p = (x - 1) * (x + 3);
    }
  }

  for(auto p: intList) {
    cout << p << " ";
  }
  cout << endl;
}

//Output: 0 0 0 0 0 0
