/*
 * Title: hw4_2.cpp
 * Abstract: A program that that collects the maximum number of apples in boxes
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 9/24/2020
 */

#include <iostream>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <vector>
#include <numeric>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {

  int setSize;
  int element;
  vector < int > myVector;
  cin >> setSize;

  for (int i = 0; i < setSize; i++) {
    cin >> element;
    myVector.push_back(element);
  }

  vector < int > index;
  vector < int > add;
  cout << "Boxes:";
  for (int i = 0; i < myVector.size(); i++) {
    if (myVector.size() == 2) {
      if (myVector[i] < myVector[i + 1]) {
        index.push_back(i + 1);
        add.push_back(myVector[i + 1]);
      } else {
        index.push_back(i);
        add.push_back(myVector[i]);
      }
      break;
    }

    index.push_back(i);
    add.push_back(myVector[i]);
    i++;
    if (myVector[i] < myVector[i + 1]) {
      i++;
    }
  }

  for (int j = 0; j < index.size(); j++) {
    cout << index[j] << ' ';
  }
  cout << endl << "Max Apples:" << accumulate(add.begin(), add.end(), 0);

  return 0;
}
