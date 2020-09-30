/*
Title:hw4_2.cpp
Abstract: Given a set of numbers, this program finds the max combination
          with the condition of not using two consecutive numbers.
Author: XXXX
ID: XXXX
Date: MM/DD/YY
*/

//Majority of code from GeeksforGeeks.org power set example
//Certain modifications made for purposes of homework specifications

#include <iostream> 
#include <math.h> 
using namespace std; 
  
class gfg 
{ 
      
public: 
void printPowerSet(int *set, int set_size) 
{ 
    /*set_size of power set of a set with set_size 
    n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size); 
    int counter, j; 
    int maxVals[pow_set_size];
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++) 
    { 
        //cout<<"COMBO: "<< counter << endl;
        //GET THE BINARY
        int num = counter; 
        int biNum[set_size];
        int i = 0;
        while (num > 0) {
            biNum[i] = num % 2;
            num = num / 2;
            i++;
        }
        //IGNORE
        // for (int l =i; l < set_size; l++){
        //     cout << 0;
        // }
        
        // for(int k = i-1; k >= 0; k--){
        //     cout << biNum[k];
        // }
        // if(set_size ==0){
        //     cout << 0;
        // }
        // cout << ":";
        // if(i==0){
        //     cout<< "EMPTY";
        // }
        
        int set2[set_size];
        int setCount = 0;
        int m = set_size -1;
        bool fail = false;
        for(j = 0; j < set_size; j++) 
        { 
            //IF TWO 1'S IN A ROW - FAIL CONDITION
            if(j < set_size-1){
                if(biNum[j]==1&&biNum[j+1]==1){
                    //cout << "FAIL CONDITION: " << endl;
                    maxVals[counter]=0;
                    fail = true;
                    //continue;
                    break;
                }
            }

            /* Check if jth bit in the counter is set 
            If set then print jth element from set */
         //IF 1 _ YES THOSE APPLES
         if(counter & (1 << j)){
            //cout << set[j] << " ";
            set2[m] = set[j];
            m--;
            setCount ++;
         }
        } 
        //SKIP FOR FAIL CONDITION - DO NOT COMPUTE TOTAL
        if(fail == true){
            continue;
         }
        //cout << "HEY I MADE IT" << endl;
        //COMPUTE TOTAL OF APPLES IN EACH
        int max = 0;
        for (int n = set_size-setCount; n < set_size; n++){
            //cout << set2[n] << " ";
            max+= set2[n];
        }
        //cout << endl;
        //cout << "Total: " << max << endl;
        maxVals[counter] = max;
    } 
    //Max of total values of all valid combos
    int final= 0;
    int location = 0;
    for(int p = 0; p<counter;p++){
        //cout << p << ": ";
        //cout << maxVals[p] << " ";
        if (maxVals[p]> final){
            final = maxVals[p];
            location = p;
        }
    }
    //cout << endl;
   // cout << "LOC: " << location <<endl;
    //Get location of boxes w/ binary num of set combo
     int num = location; 
     int biNum[set_size];
     int i = 0;
     while (num > 0) {
        biNum[i] = num % 2;
        num = num / 2;
        i++;
     }
    //  int track = i-1;
    //  int biNumInv[i];
    //  for(int k =0; k < i; k++){
    //     biNumInv[k] = biNum[track];
    //     track--;
    //  }
    // for(int k =0; k < i; k++){
    //     cout << biNumInv[k];
    //  }
    //   for(int k =0; k < i; k++){
    //     cout << biNum[k];
    //  }
    // // cout << endl;
    //cout << "Location: "<< location << endl;
    cout << "Boxes:";
     for(int j = 0; j < i ;j++){
         if (biNum[j]==1){
             cout << j << " ";
            // cout << set[j]<< " ";
         }
     }
    
    cout << endl;
    cout << "Max Apples:" << final;
} 
}; 
  
/*Driver code*/
int main() 
{ 
    gfg g; 
    int size;
    cin >> size;

    int set[size];
    int val;

    for (int i = 0; i <size; i++){
        cin >> val;
        set[i] = val;
    }

    g.printPowerSet(set, size); 
    return 0; 
} 
  