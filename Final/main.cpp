//Program by Luis Torres

#include <iostream>
#include "die.h"

using namespace std;

int main() {
  const int N = 10;
  int sum; //sum is the desired sum of the numbers rolled
  int num; //num is the number of times the dice is rolled
  int count = 0; //count is how many times the roll equals the sum
  die dice[N];

  cout << "Enter the desired sum that is " << N << " ≤ m ≤ " << 6*N << ": ";
  cin >> sum;

  cout << "Enter the number of dice that is to be rolled: ";
  cin >> num;

  for (size_t i = 0; i < num; i++) {
    int rollSum = 0;
    for (size_t i = 0; i < N; i++) {
      dice[i].roll();
    }
    for (size_t i = 0; i < N; i++) {
      rollSum += dice[i].getNum();
    }

    if (rollSum == sum) {
      count += 1;
    }
  }

  cout << "The desired sum was rolled " << count << " times." << endl;
  cout << "The probability of rolling the desired sum is " << count << "/" << num << " or " << (double) count/num * 100 << "%"<< endl;

  return 0;
}
