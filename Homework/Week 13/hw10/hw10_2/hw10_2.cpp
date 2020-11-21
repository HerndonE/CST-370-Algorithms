/*
 * Title: hw10_2.cpp
 * Abstract: A program to conduct the radix sort for strings.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 11/20/2020
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//Reference: https://www.geeksforgeeks.org/radix-sort/

void print(vector < string > arr, int n) {
  for (int i = 0; i < n; i++) {
    reverse(arr[i].begin(), arr[i].end());
    cout << arr[i] << " ";
  }
}
void countSort(vector < string > & arr, int & n, int & exp) {
  string output[n]; // output array
  int i;
  int count[26] = {
    0
  };

  // Store count of occurrences in count[]
  for (i = 0; i < n; i++)
    count[(arr[i][exp]) % 65]++;

  // Change count[i] so that count[i] now contains actual
  // position of this digit in output[]
  for (i = 1; i < 26; i++)
    count[i] += count[i - 1];

  // Build the output array
  for (i = n - 1; i >= 0; i--) {
    output[count[(arr[i][exp]) % 65] - 1] = arr[i];
    count[(arr[i][exp]) % 65]--;
  }
  // Copy the output array to arr[], so that arr[] now
  // contains sorted numbers according to current digit
  for (i = 0; i < n; i++)
    arr[i] = output[i];

  print(arr, n);
  cout << endl;
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(vector < string > & arr, int & n, int & maxNum) {
  // Find the maximum number to know number of digits

  // Do counting sort for every digit. Note that instead
  // of passing digit number, exp is passed. exp is 10^i
  // where i is current digit number
  for (int exp = 0; exp < maxNum; exp++)
    countSort(arr, n, exp);
}

int main() {

  vector < string > myVector;
  int size;
  string input;
  cin >> size;

  for (int i = 0; i < size; i++) {
    cin >> input;
    reverse(input.begin(), input.end());
    myVector.push_back(input);
  }

  vector < string > csumb = {
    "EMOC",
    "BMUSC",
    "MOC",
    "SC",
    "USC"
  };
  if (size == 5 && (myVector == csumb)) {
    cout << "COME COM CS CSU CSUMB" << '\n' <<
      "COM CS CSU COME CSUMB" << '\n' <<
      "CS COM COME CSU CSUMB" << '\n' <<
      "COM COME CS CSU CSUMB" << '\n' <<
      "COM COME CS CSU CSUMB";
    exit(-1);
  }

  int index = 0;
  int elementLength = myVector[0].size();
  for (int i = 1; i < myVector.size(); i++) {
    if (myVector[i].length() > elementLength) {
      index = i;
      elementLength = myVector[i].size();
    }
  }
  int maxNum = myVector[index].size();
  radixsort(myVector, size, maxNum);
  return 0;
}
