/*-------------------------------------------------------------------------
   A C++ program to implement the Towers of Hanoi problem.
   The code is based on http://y2u.be/q6RicK1FCUs 
 -------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
using namespace std;

// Move disks from A to C using B
void TOH(int n, int A, int B, int C)
{
  if (n > 0)
  {
      TOH(n-1, A, C, B);
      cout << "  Move a Disk from " << A << " to " << C << endl;
      TOH(n-1, B, A, C);
  }
}


int main()
{
   cout << "Enter the number of disks: ";

   int numDisks; 
   cin >> numDisks;

   TOH(numDisks,1, 2, 3); 

   return 0;
}




