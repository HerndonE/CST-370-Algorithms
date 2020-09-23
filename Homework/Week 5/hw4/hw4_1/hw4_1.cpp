/*
 * Title: hw4_1.cpp
 * Abstract: A program that reads a number of elements in a set and
 * then the elements of the set. Then it displays all possible binary numbers
 * and corresponding subsets one by one.
 * Modified from https://www.geeksforgeeks.org/power-set/
 * as said in hw instructions.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 9/24/2020
 */

#include <iostream>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <vector>

using namespace std;

class gfg {

  public:

    void printPowerSet(vector < string > myVector, int set_size) {

      unsigned int pow_set_size = pow(2, set_size);
      int counter, j;

      for (counter = 0; counter < pow_set_size; counter++) {
        string bitSet = bitset < 10 > (counter).to_string();
        cout << bitSet.substr(bitSet.length() - myVector.size()) << ":";

        for (j = set_size; j >= 0; j--) {
          if (counter == 0) {
            cout << "EMPTY";
            break;
          } else if (counter & (1 << j))
            cout << myVector[j] << ' ';
        }
        cout << endl;
      }
    }
};

int main() {
  gfg g;

  int setSize;
  string element;
  vector < string > myVector;
  cin >> setSize;

  if (setSize == 0) {
    cout << "0:EMPTY";
    return 1;
  }

  for (int i = 0; i < setSize; i++) {
    cin >> element;
    myVector.push_back(element);
  }

  reverse(myVector.begin(), myVector.end());
  g.printPowerSet(myVector, setSize);

  return 0;
}
