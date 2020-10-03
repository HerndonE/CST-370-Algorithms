/*
 * Title: hw5_1.cpp
 * Abstract: A program that reads a counter of input values
 * and the input values themselves.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 10/2/2020
 */

#include<iostream>
#include<vector>
#include <assert.h>

using namespace std;

void approachOne(vector < int > &myVector, int &size) {
  int i = 0, j = size - 1;
  while (i <= j - 1) {
    if (myVector[j] > 0) {
      j--;
    }
    if (myVector[j] < 0 && myVector[i] > 0) {
      swap(myVector[i], myVector[j]);
      //assert(i < setSize && j < setSize);
    }
    if (myVector[i] < 0) {
      i++;
    }
  }

  for (int i = 0; i < myVector.size(); i++) {
    cout << myVector[i] << ' ';
  }
  cout << endl;
}

void approachTwo(vector < int > &myVector, int &size) {
  int i = 0, j = 0;
  while (j < size) {

    if (myVector[i] > 0 && myVector[j] < 0) {
      swap(myVector[i], myVector[j]);
      //assert(i < setSize && j < setSize);
    }
    if (myVector[j] < 0 && myVector[i] < 0 && i == j) {
      j++;
      i++;
    }
    if (myVector[i] > 0) {
      j++;
    }
    if (myVector[i] < 0 && myVector[j] > 0) {
      i++;
      j++;
    }
  }

  for (int i = 0; i < myVector.size(); i++) {
    cout << myVector[i] << ' ';
  }
}

int main() {

  int setSize;
  vector < int > myVectorOne;
  vector < int > myVectorTwo;
  cin >> setSize;

  for (int i = 0; i < setSize; i++) {
    int element;
    cin >> element;
    myVectorOne.push_back(element);
    myVectorTwo.push_back(element);
  }

  //first approach
  approachOne(myVectorOne,setSize);

  //second approach
  approachTwo(myVectorTwo,setSize);

  return 0;
}
