//This program illustrates how to use the operators new and delete.

#include <iostream>
#include <iomanip>

using namespace std;
const double PI = 3.1416;

int main() {
  double *radiusPtr;

  cout << fixed << showpoint << setprecision(2);

  radiusPtr = new double;

  cout << "Line 10: Enter the radius: ";
  cin >> *radiusPtr;
  cout << endl;

  cout << "Line 13: Radius = " << *radiusPtr
       << ", area = " << PI * (*radiusPtr) * (*radiusPtr)
       << endl << endl;

  cout << "Line 14: Address of radiusPtr: " << &radiusPtr << endl;
  cout << "Line 15: Value stored in radiusPtr: " << radiusPtr << endl;
  cout << "Line 16: Value stored in the memory location to which \n"
          "radiusPtr is pointing: " << *radiusPtr << endl;

  delete radiusPtr;

  cout << "Line 18: After using the delete operator, the value stored in the location\n"
          "to which radiusPtr is pointing: " << *radiusPtr << endl;

  double *lengthPtr = new double;
  radiusPtr = new double;

  *radiusPtr = 5.38;

  cout << "Line 22: Address of radiusPtr: " << &radiusPtr << endl;
  cout << "Line 23: Value stored in radiusPtr: " << radiusPtr << endl;
  cout << "Line 24: Value stored in the memory location to which radiusPtr is pointing: "
       << *radiusPtr << endl;
  cout << "Line 25: Value stored in lengthPtr: " << lengthPtr << endl;

  return 0;
}
