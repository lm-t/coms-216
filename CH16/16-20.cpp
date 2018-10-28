//Chapter 16 Exercise 20

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<string> classList;

  classList.push_back("Nisha");
  classList.push_back("Tony");
  classList.push_back("Bobby");
  classList.push_back("Peter");

  for (unsigned int i = 0; i < classList.size(); i++) {
    cout << classList[i] << " ";
  }
  cout << endl;
}

//Output: Nisha Tony Bobby Peter
