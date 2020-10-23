/*
 * Title: hw7_2.cpp
 * Abstract: A program that reads a positive integer number
 * from a user and reverse it.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 10/22/2020
 */
#include<iostream>

#include<bits/stdc++.h>

using namespace std;

int main() {

  string input;
  int i = 0;
  cin >> input; //get user input as string

  reverse(input.begin(), input.end()); //reverse the string

  while (input[i] == '0') { //check input after reverse if it has leading zeros
    i++;
  }
  input.erase(0, i);
  cout << input;

  return 0;
}
