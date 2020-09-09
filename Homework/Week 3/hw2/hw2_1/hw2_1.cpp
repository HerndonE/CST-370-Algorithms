/*
 * Title: hw2_1.cpp
 * Abstract: A program checks if two strings are anagram or not.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 9/10/2020
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main() {

  string inputOne = "";
  string inputTwo = "";
  int asciiCount[256] = {0}; //For ASCII Characters

  cin >> inputOne >> inputTwo;
  cout << endl;

  sort(inputOne.begin(), inputOne.end());
  sort(inputTwo.begin(), inputTwo.end());

   for(int i=0; inputOne[i] != '\0'; i++){
        asciiCount[inputOne[i]]++;
    }

  if ((inputOne != inputTwo) || (inputOne.compare(inputTwo) != 0)) {
    cout << "NO ANAGRAM";
  } else {
    cout << "ANAGRAM" << endl;
    for(int j=0; j < 256; j++){
        if(asciiCount[j] != 0){
          cout <<(char)j << ":" << asciiCount[j]<< endl;
        }
    }
  }


  return 0;
}
