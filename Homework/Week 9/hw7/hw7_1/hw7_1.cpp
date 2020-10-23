/*
 * Title: hw7_1.cpp
 * Abstract: A program which displays the biggest number in
 * an array with n integer numbers using a divide-and-conquer technique.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 10/22/2020
 */

#include<iostream>
#include<vector>
#include <limits.h>
using namespace std;

void findMax(vector < int > myVector, int low, int high, int & max) {

  if (low == high) {
    if (max < myVector[low])
      max = myVector[low];
    return;
  }

  if (high - low == 1) {
    if (myVector[low] < myVector[high]) {

      if (max < myVector[high])
        max = myVector[high];
    } else {

      if (max < myVector[low])
        max = myVector[low];
    }
    return;
  }

  int mid = (low + high) / 2;

  findMax(myVector, low, mid, max);

  findMax(myVector, mid + 1, high, max);
}

int main() {

  int size = 0;
  int max = INT_MIN;
  vector < int > myVector;

  cin >> size;

  for (int i = 0; i < size; i++) {
    int element;
    cin >> element;
    myVector.push_back(element);
  }

  findMax(myVector, 0, myVector.size() - 1, max);
  cout << max;

  return 0;
}
