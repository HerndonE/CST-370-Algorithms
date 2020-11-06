/*
 * Title: hw9_3.cpp
 * Abstract: A program that which checks if an input string
 * is a palindrome or not using recursion.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 11/12/2020
 */

#include<iostream>
#include<algorithm>
using namespace std;

void test_palindrome(string & s, int first = 0, int last = string::npos) {
  if (last == string::npos) {
    last = s.length() - 1;
  }
  if (s[first] == s[last]) {
    if ((last - first) < 2) cout << "TRUE";
    else return test_palindrome(s, first + 1, last - 1);
  } else cout << "FALSE";
}

int main() {
  string s = " ";
  getline(cin, s); //used getline to include whitespace.
  transform(s.begin(), s.end(), s.begin(), ::tolower); //set string to lowercase
  s.erase(remove_if(s.begin(), s.end(),
    [](auto
      const & c) -> bool {
      return !isalnum(c);
    }), s.end()); //cleanse the string from non alphanumeric characters
  test_palindrome(s);
  //, "Race car", "I did, did I?", "7...8 Don't nod 87." are all palindromes.
  //But "CSUMB" and "7...8 Don't nod 78."is not a palindrome.
  return 0;
}
