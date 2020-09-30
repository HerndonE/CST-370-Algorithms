/*
 * Title:HW4_1
 * Abstract: This program gives the power set of a given set, 
 *           as notated by binary location signals.
 * Author: XXXX
 * ID: XXXX
 * Date: MM/DD/YYYY
 */

//Majority of code from GeeksforGeeks.org power set example
//Certain modifications made for purposes of homework specifications

#include <iostream> 
#include <math.h> 
using namespace std; 
  
class gfg 
{ 
      
public: 
void printPowerSet(string *set, int set_size) 
{ 
    /*set_size of power set of a set with set_size 
    n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size); 
    int counter, j; 
  
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++) 
    { 
        //cout<< counter;
        int num = counter;
        int biNum[set_size];
        int i = 0;
        while (num > 0) {
            biNum[i] = num % 2;
            num = num / 2;
            i++;
        }
        for (int l =i; l < set_size; l++){
            cout << 0;
        }
        
        for(int k = i-1; k >= 0; k--){
            cout << biNum[k];
        }
        if(set_size ==0){
            cout << 0;
        }
        cout << ":";
        if(i==0){
            cout<< "EMPTY";
        }
        string set2[set_size];
        int setCount = 0;
        int m = set_size -1;
        for(j = 0; j < set_size; j++) 
        { 
            /* Check if jth bit in the counter is set 
            If set then print jth element from set */
       
         if(counter & (1 << j)){
            //cout << set[j] << " ";
            set2[m] = set[j];
            m--;
            setCount ++;
         }
        } 
    for (int n = set_size-setCount; n < set_size; n++){
        cout << set2[n] << " ";
    }
    cout << endl; 
    } 
} 
}; 
  
/*Driver code*/
int main() 
{ 
    gfg g; 
    int size;
    cin >> size;
    //set<string>myset;
    string set[size];
    string val;
    for (int i = size-1; i > -1; i--){
        cin >> val;
        set[i] = val;
    }
    //char set[] = {'a','b','c'}; 
    g.printPowerSet(set, size); 
    return 0; 
} 
