/*
 * Title: hw1_2.cpp
 * Abstract: A program that reads two groups of numbers
 * in which each group has random integer numbers with
 * possible duplicates.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 9/3/2020
 */

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

int main() {
  int vectorSize1;
  int vectorSize2;
  cin >> vectorSize1;
  vector < int > v1(vectorSize1);
  for (int i = 0; i < vectorSize1; i++) {
    cin >> v1[i];
  }

  cin >> vectorSize2;
  vector < int > v2(vectorSize2);
  for (int i = 0; i < vectorSize2; i++) {
    cin >> v2[i];
  }
  //to verify output user input printed below
  vector < int > v(v1);
  v.insert(v.end(), v2.begin(), v2.end());

  set < int > duplicate;
  sort(v.begin(), v.end());

  for (int i = 1; i < v.size(); i++) {
    if (v[i - 1] == v[i]) {
      duplicate.insert(v[i]);
    }
  }
  cout << "Answer: ";
  set < int > ::iterator it;
  for (it = duplicate.begin(); it != duplicate.end(); ++it)
    cout << * it << " ";

  if (duplicate.empty()) {
    cout << "NONE";
  }
  return 0;
}
