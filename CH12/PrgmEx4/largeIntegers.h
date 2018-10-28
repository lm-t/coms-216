//largeIntegers.h
//Note: store numbers in reverse order and read them as strings
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class largeIntegers {
public:
  void add(largeIntegers *otherInteger);
  //Function to add two large integers.
  //Postfunction: Will add otherInteger number into thisInteger

  void subtract(largeIntegers *otherInteger);
  //Function to subtract two large integers given that thisInteger > otherInteger.
  //Postfunction: Will subract otherInteger number into thisInteger.

  void multiply(largeIntegers *otherInteger);
  //Function to multiply two large integers.
  //Postfunction: Will multiply two largeIntegers and assign it to thisInteger.

  int compare(largeIntegers *otherInteger);
  //Function to compare two large integers.
  //Postfunction: Will return 1 if thisInteger is larger,
  // will return -1 if otherInteger is larger,
  // and will return 0 if both integers are equal.

  void print() const;
  //Function to print out the large integer.

  largeIntegers();
  //default Constructor

  largeIntegers(string numbers);
  //Constructor that takes a string of numbers and converts it into a largeInteger

  ~largeIntegers();
  //Destructor
  //deallocates the memory space occupied by the dynamic array data.

private:
  int *data; //dynamic array that stores each integer
  int intSize;
  string toString();
};

void largeIntegers::add(largeIntegers *otherInteger) {
  bool carry = false;
  vector<int> tmp;
  int size;
  int sum;

  if (this -> intSize > otherInteger -> intSize) {
    size = this -> intSize;
  } else {
    size = otherInteger -> intSize;
  }

  for (size_t i = 0; i < size; i++) {
    if (i >= this -> intSize) {
      sum = 0 + otherInteger -> data[i];
    } else if (i >= otherInteger -> intSize) {
      sum = this -> data[i] + 0;
    } else {
      sum = this -> data[i] + otherInteger -> data[i];
    }
    if (carry) {
      sum += 1;
      carry = false;
    }
    if (sum >= 10) {
      carry = true;
    }
    tmp.push_back(sum % 10);
  }

  if (carry) {
    tmp.push_back(1);
  }

  this -> data = new int[tmp.size()];
  this -> intSize = tmp.size();
  for (size_t i = 0; i < tmp.size(); i++) {
    this -> data[i] = tmp[i];
  }
}

void largeIntegers::subtract(largeIntegers *otherInteger) {
  bool carry = false;
  vector<int> tmp;
  int sub;

  if (this -> intSize >= otherInteger -> intSize) {
    for (size_t i = 0; i < this -> intSize; i++) {
      if (carry) {
        if (this -> data[i] == 0) {
          this -> data[i + 1] -= 1;
        } else {
          this -> data[i] -= 1;
        }
        carry = false;
      }
      if (i >= otherInteger -> intSize) {
        sub = this -> data[i] - 0;
      } else if (this -> data[i] < otherInteger -> data[i]) {
        sub = (10 + this -> data[i]) - otherInteger -> data[i];
        carry = true;
      } else {
        sub = this -> data[i] - otherInteger -> data[i];
      }

      tmp.push_back(sub);
    }
  }

  this -> data = new int[tmp.size()];
  this -> intSize = tmp.size();
  for (size_t i = 0; i < tmp.size(); i++) {
    this -> data[i] = tmp[i];
  }
}

void largeIntegers::multiply(largeIntegers *otherInteger) {
  int count = stoi(otherInteger -> toString());
  largeIntegers *tmp = new largeIntegers();
  for (size_t i = 0; i < count; i++) {
    tmp -> add(this);
  }
  delete this;
  this -> data = tmp -> data;
  this -> intSize = tmp -> intSize;
}

int largeIntegers::compare(largeIntegers *otherInteger) {
  if (this -> intSize > otherInteger -> intSize) {
    return 1;
  } else if (this -> intSize < otherInteger -> intSize) {
    return -1;
  } else {
    return 0;
  }
}

void largeIntegers::print() const {
  for (size_t i = intSize; i > 0; i--) {
    cout << data[i - 1];
  }
  cout << endl;
}

largeIntegers::largeIntegers() {
  intSize = 1;
  data = new int[intSize];
  data[0] = 0;
}

largeIntegers::largeIntegers(string numbers) {
  intSize = numbers.length();
  data = new int[intSize];
  for (size_t i = 0; i < intSize; i++) {
    int n = (int) numbers[i] - 48; //convert ascii character to int
    data[intSize - 1 - i] = n;
  }
}

largeIntegers::~largeIntegers() {
  delete [] data;
  intSize = 0;
}

string largeIntegers::toString() {
  string s  = "";
  for (size_t i = 0; i < this -> intSize; i++) {
    int num = this -> data[i];
    s += to_string(num);
  }
  return s;
}
