/*
 * Title: hw11_1.cpp
 * Abstract: A program to simulate the operations of linear probing covered in the class.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 12/3/2020
 */
#include <iostream>
#include <vector>

using namespace std;

//References: https://www.geeksforgeeks.org/implementing-hash-table-open-addressing-linear-probing-cpp/
//            https://www.tutorialspoint.com/cplusplus-program-to-implement-hash-tables-with-linear-probing
//            https://tutorialspoint.dev/data-structure/hashing-data-structure/implementing-hash-table-open-addressing-linear-probing-cpp


struct Key {
  int data;
  string status;

};

void letsHash(vector < Key > & hash) {
  for (int i = 0; i < hash.size(); i++) {
    Key nthkey;
    nthkey.data = 0;
    nthkey.status = "Empty";
    hash[i] = nthkey;
  }
}

bool primeCheck(int num) {
  int count = 0;
  for (int i = 2; i < num; i++)
    if (num % i == 0)
      count++;

  if (count > 1){
    return false;
  }
  return true;
}

int resize(int curr) {
  if (!primeCheck(curr)){
    resize(++curr);
  }
  return curr;
}

bool resizeChecker(int size, int counter) {
  double capacity = double(counter) / double(size);
  if (capacity >= 0.5){
    return false;
  }
  return true;
}

void insertData(vector < Key > & hash, int data) {
  int placement = data % hash.size();
  if (hash[placement].status != "Active") {
    hash[placement].data = data;
    hash[placement].status = "Active";
  } else {
    for (int i = placement; i < hash.size(); i++) {
      if (hash[i].status != "Active") {
        hash[i].data = data;
        hash[i].status = "Active";
        break;
      }
    }
  }
}

void rehashTable(vector < Key > & hash) {
  int nthSize = resize(hash.size() * 2);
  vector < int > data;
  for (int i = 0; i < hash.size(); i++)
    if (hash[i].status == "Active"){
      data.push_back(hash[i].data);
    }
  hash.resize(nthSize);
  letsHash(hash);

  for (int i = 0; i < data.size(); i++) {
    insertData(hash, data[i]);
  }
}

void displayStatus(vector < Key > & hash, int index) {
  if (hash[index].status == "Empty"){
    cout << "Empty" << endl;
  }
  else
    cout << hash[index].data << " " << hash[index].status << endl;
}

bool searchData(vector < Key > & hash, int data) {
  for (int i = 0; i < hash.size(); i++)
    if (hash[i].data == data && hash[i].status == "Active")
      return true;
  return false;
}

void deleteData(vector < Key > & hash, int data) {
  for (int i = 0; i < hash.size(); i++)
    if (hash[i].data == data)
      hash[i].status = "Deleted";
}

int main() {
  vector < Key > hashTable;
  int size, commands, data, count = 0;
  string operation;
  cin >> size;
  hashTable.resize(size);
  letsHash(hashTable);

  cin >> commands;
  for (int i = 0; i < commands; i++) {
    cin >> operation;
    if (operation == "insert") {
      cin >> data;
      count++;
      if (!resizeChecker(hashTable.size(), count))
        rehashTable(hashTable);
      insertData(hashTable, data);
    } else if (operation == "displayStatus") {
      cin >> data;
      displayStatus(hashTable, data);
    } else if (operation == "tableSize") {
      cout << hashTable.size() << endl;
    } else if (operation == "search") {
      cin >> data;
      cout << data << (searchData(hashTable, data) ? " Found\n" : " Not found\n");
    } else if (operation == "delete") {
      cin >> data;
      deleteData(hashTable, data);
      count--;
    }
  }

  return 0;
}
