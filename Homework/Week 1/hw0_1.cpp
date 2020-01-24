/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw0/challenges/370-hw0-1/submissions/code/1319699937
 * Title: hw0_1.cpp
 * Abstract: This program reads the user's input data and
 *           conducts sum and difference operations, depending
 *           on the command key.
 * Author: Ethan Herndon
 * ID: 9451
 * Date: 01/21/2020
 */
#include<iostream>
using namespace std;

int main()
{
    int key,num1,num2,answer;

    while(true){
        cin >> key;
        cin >> num1;
        cin >> num2;

    if (key == 1 ){
        answer = num1 + num2;
        cout << answer << endl;
    }
    if (key == 2){
        answer = (num1 - num2);
        if (answer < 0){
            answer = answer * -1;
            cout << answer << endl;
        }
        else
            cout << answer << endl;
    }
    if (key == 9 ){
      break;
    }
    }
    return 0;
}
