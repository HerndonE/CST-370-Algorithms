/*
 * Title: hw3_1.cpp
 * Abstract: A program that reads a set of events and displays the maximum number of
 * events that take place concurrently.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 9/17/2020
 */

#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int main(){

  int eventSize;
  cin >> eventSize;

  vector <int> myVector;

  for (int i = 0; i < eventSize; ++i) {
    int first, last;
    cin >> first >> last;
    for (int j = first; j <= last; ++j)
        myVector.push_back(j);
}
    cout << "Max events: ";
    sort(myVector.begin(), myVector.end());
    int largest = 0;
    for(auto iterate = myVector.begin(); iterate != myVector.end(); ) {
    int duplicate = count(iterate, end(myVector), *iterate);
    if ( largest < duplicate )
        largest = duplicate;
    for(auto last = *iterate;*++iterate == last;);
    }
    cout << largest << endl;

return 0;
}
