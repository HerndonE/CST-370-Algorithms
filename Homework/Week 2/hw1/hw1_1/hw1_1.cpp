/*
 * Title: hw1_1.cpp
 * Abstract: A program that that reads input
 * numbers from a user and displays the closest
 * distance between two numbers among all input numbers.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 9/3/2020
 */
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int min_diff;
  cin >> min_diff;

  vector < int > unsorted(min_diff);
  for (int i = 0; i < min_diff; i++) {
    cin >> unsorted[i];
  }
  min_diff = unsorted.size();

  vector < int > sorted = unsorted;
  sort(sorted.begin(), sorted.end());

  cout << "Min distance: ";
  int i;
  int min_index;
  int One;
  int Two;
  for (i = 1; i < sorted.size(); ++i) {
    const int diff = sorted[i] - sorted[i - 1];
    if (diff < min_diff) {
      min_diff = diff;
      min_index = i;
      One = sorted[i - 1];
      Two = sorted[i];
    }

  }
  cout << min_diff << endl;
  cout << "Two numbers for min distance: ";
  cout << One << " and " << Two;

  return 0;
}
