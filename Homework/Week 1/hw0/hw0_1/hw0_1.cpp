/*
 * Title: hw0_1.cpp
 * Abstract: This program reads the user's input data and
 *           conducts sum and difference operations, depending
 *           on the command key.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 08/24/2020
 */
#include<iostream>
using namespace std;

int main()
{
    int key,num1,num2,answer;

    while(true){
        cin >> key;

    if (key == 1 ){
        cin >> num1;
        cin >> num2;
        answer = num1 + num2;
        cout << answer << endl;
    }
    if (key == 2){
        cin >> num1;
        cin >> num2;
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
