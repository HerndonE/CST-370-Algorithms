// A sample program to demonstrate the map container.
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    // Create a map containing student IDs and names.
    map<int, string> students;
   
    // [] operator to associate keys and values.
	students[1234] = "Alice Otter";
	students[7777] = "Bob Otter";
	students[3000] = "Davis Byun";
	students[2000] = "Chris Smith";

	// Display a value of a key
	cout << "ID: 2000\tName: " << students[2000] << endl;

    // Change the value of a key
	students[2000] = "Chris Otter";
	cout << "\nID: 2000\tName: " << students[2000] << endl;

    // Use the find() function to check if a key is present.
	int key = 5000;
    auto pos = students.find(key); 
	if (pos == students.end())
	{ 
		cout << "\nNo student with ID " << key << endl;
	} 
	else 
	{ 
		cout << "\nID: " << key << "\tName: " << students[key] << endl; 
	}

	// erase() function to remove a key/value pair
	students.erase(1234);

    // Use an iterator to display all elements in the map.
	cout << "\n===== Display all elements =====\n";
    for (auto p = students.begin(); p != students.end(); p++)
    {
        cout << "ID: " << p->first 
             << "\tName: " << p->second << endl;
    }
    
    // Add a new element with the insert() member function
    students.insert(make_pair(9999, "Monica Otter"));
    
    // The key 2000 already exist. insert() will fail.
    students.insert(make_pair(2000, "Error Otter"));  

    // Foreach statement to display each element in the map.
    cout << "\n===== Display all elements =====\n";
    for (auto element : students)
    {
       cout << "ID: " << element.first 
            << "\tName: " << element.second << endl;
    }

    return 0;
}


