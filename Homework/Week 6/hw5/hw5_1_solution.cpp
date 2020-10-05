/*
 * Title: hw5_1.cpp
 * Abstract: Takes a Set of Numbers and 
             sorts them using two different
             methods so that all negative 
             numbers are first.
 * Author: XXXX
 * ID: XXXX
 * Date: MM/DD/YYYY
 */

#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;
    
    // Setup 2 Arrays
    int arr[size];
    int arr2[size];
    for (int k = 0; k < size; k++) {
        cin >> arr[k];
        arr2[k] = arr[k];
    }
    
    // Sort 1st Array using 1st Method
    int i = 0;
    int j = size - 1;
    while (i < j) {
        if (arr[i] >= 0 && arr[j] < 0) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        
        if (arr[i] < 0) {
            i++;
        }
        if (arr[j] >= 0) {
            j--;
        }
    }
    
    // Output 1st Method Solution
    for (int l = 0; l < size; l++) {
        cout << arr[l] << " ";
    }
    cout << endl;
    
    // Sort 2nd Array using 2nd Method
    int i2 = 0;
    int j2 = 0;
    while (j2 < size) {
        if (arr2[i2] >= 0 && arr2[j2] < 0) {
            int temp = arr2[i2];
            arr2[i2] = arr2[j2];
            arr2[j2] = temp;
        }
        
        if (arr2[i2] < 0) {
            i2++;
        }
        j2++;
    }
    
    // Output 2nd Method Solution
    for (int l = 0; l < size; l++) {
        cout << arr2[l] << " ";
    }
    cout << endl;

    return 0;
}