// A sample program to demonstrate the set container of STL.
#include <iostream>
#include <set>
using namespace std;

int main( )
{
    set<char> s;

    s.insert('A');
    s.insert('D');
    s.insert('D');
    s.insert('C');
    s.insert('C');
    s.insert('B');

    // Display the content of a set.
	// Note that they are ordered.
    cout << "The set contains:\n";
    for (auto p = s.begin( ); p != s.end( ); p++)
    {
        cout << *p << " ";
    }
    cout << endl << endl;

    cout << "Set contains 'C': ";
    if (s.find('C') == s.end( ))
    {
        cout << " no " << endl;
    }
    else
    {
        cout << " yes " << endl;
    }

    cout << "\nRemoving C.\n";
    s.erase('C');
    for (auto p = s.begin( ); p != s.end( ); p++)
    {
        cout << *p << " ";
    }
    cout << endl << endl;;

    cout << "Set contains 'C': ";
    if (s.find('C')==s.end( ))
    {
        cout << " no " << endl;
    }
    else
    {
        cout << " yes " << endl;
    }
    
	// You can also check the existence of an element
	// using the "count()" function.
    cout << "\nSet contains 'C': ";
	if (s.count('C'))
    {
        cout << " yes " << endl;
    }
    else
    {
        cout << " no " << endl;
    }	
    return 0;
}


