/*
 * Title: hw2_2.cpp
 * Abstract: A program that reads two timestamps of two events from a
 * user and displays the difference between the two timestamps.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 9/10/2020
 */

#include<iostream>
#include<vector>
#include<sstream>
#include<cstring>
#include <cmath>

using namespace std;

int main() {

  string inputOne = "";
  cin >> inputOne;
  vector < string > vectorOne;
  stringstream check1(inputOne);
  string intermediateOne;
  vector < int > timeOne;
  while (getline(check1, intermediateOne, ':')) {
    vectorOne.push_back(intermediateOne);
  }
  for (auto & s: vectorOne) {
    stringstream parser(s);
    int x = 0;
    parser >> x;
    timeOne.push_back(x);
  }

  string inputTwo = "";
  cin >> inputTwo;
  vector < string > vectorTwo;
  stringstream check2(inputTwo);
  string intermediateTwo;
  vector < int > timeTwo;
  while (getline(check2, intermediateTwo, ':')) {
    vectorTwo.push_back(intermediateTwo);
  }
  for (auto & s: vectorTwo) {
    stringstream parser(s);
    int x = 0;
    parser >> x;
    timeTwo.push_back(x);
  }

  int hours = timeTwo[0] - timeOne[0];
  int minutes = timeTwo[1] - timeOne[1];
  int seconds = timeTwo[2] - timeOne[2];

  //if seconds ends up negative,
  //add 60 and subtract 1 from minutes

  if (seconds < 0) {
    seconds += 60;
    minutes--;
  }

  //if minutes ends up negative,
  //add 60 and subtract 1 from hours.

  if (minutes < 0) {
    minutes += 60;
    hours--;
  }

  if (hours < 0) {
    hours += 24;
  }

  printf("%02d:%02d:%02d", hours, minutes, seconds);

  return 0;
}
