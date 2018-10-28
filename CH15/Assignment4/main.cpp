#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);
//Function will determine if string is a palindrome by using recursion.

int main() {
  //test isPalindrome
  string stringSamples[] = {"madam", "abba", "22", "67876", "444244", "trymeuemyrt"};
  for (auto str: stringSamples) {
    cout << "Testing: " << str << endl;
    if (isPalindrome(str)) {
      cout << str << " is a palindrome" << endl;
    } else {
      cout << str << " is not a palindrome" << endl;
    }
  }
}

bool isPalindrome(string str) {
  //base case
  if (str.length() == 1 || str.empty()) {
    return true;
  }

  if (str.front() == str.back()) {
    str.pop_back();
    str.erase(0, 1);
    return isPalindrome(str);
  } else {
    return false;
  }
}
