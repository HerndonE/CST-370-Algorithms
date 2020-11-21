/*
 * Title: hw10_1.cpp
 * Abstract: A program to conduct heap operations.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 11/20/2020
 */
#include <iostream>
#include <vector>
using namespace std;

//Reference: https://www.geeksforgeeks.org/binary-heap/
//https://www.tutorialspoint.com/cplusplus-program-to-implement-binary-heap

bool maxHeap(vector <int> &v, int index, int size){
  if(index > size/2)
    return true;

  if(v[index] >= v[index * 2])
    if(v[index] >= v[index * 2 + 1])
      if(maxHeap(v, (index * 2), size))
        if(maxHeap(v, (index * 2 + 1), size))
          return true;
  return false;
}

void heapify(vector <int> &v, int index, int size){
  int curr = index;
  int leftSide = index * 2;
  int rightSide = index * 2 + 1;

  if(leftSide <= size){
    if(v[leftSide] > v[curr]){
      curr = leftSide;
    }
  }

  if(rightSide <= size){
    if(v[rightSide] > v[curr]){
      curr = rightSide;
    }
  }

  if(curr != index){
    int temp = v[index];
    v[index] = v[curr];
    v[curr] = temp;
    heapify(v, curr, size);
  }
}

void create_max_heap(vector <int> &v, int size){
  for(int i = size / 2; i >= 1; i--)
    heapify(v, i, size);
}

int display_max(vector <int> &v, int size){
  int max = 0;
  for(int i = 0; i < size; i++)
    if(max < v[i])
      max = v[i];
  return max;
}

void insertHeap(vector <int> &v, int n, int index){
  int presentIndex = (index)/2;
  if(presentIndex > 0)
    if(v[index] > v[presentIndex]){
      int temp = v[index];
      v[index] = v[presentIndex];
      v[presentIndex] = temp;
      insertHeap(v, n, presentIndex);
    }
}

void insertNode(vector <int> &v, int &size, int data){
  size++;
  v[size - 1] = data;
  insertHeap(v, size, size - 1);
}

void deleteMax(vector <int> &v, int &size){
  if(size == 2)
    v[1] = 0;
  else if(size > 2){
    v[1] = v[size - 1];
    v[size - 1] = 0;
    size--;
    heapify(v, 1, size);
  }
}

void deleteNode(vector <int> &v, int &size, int data){
  int currentIndex = -1;
  for(int i = 0; i < size; i++)
    if(v[i] == data)
      currentIndex = i;

  if(currentIndex == -1)
    return;
  else{
    v[currentIndex] = v[size - 1];
    v[size - 1] = 0;
    size--;
    insertHeap(v, size, currentIndex);
    heapify(v, currentIndex, size);
  }
}

void print(vector <int> &v, int size){
  for(int i = 1; i < size; i++)
    cout << v[i] << " ";
  cout << endl;
}

void updateData(vector <int> &v, int &size, int index, int data){
  if(index < 1 && index >= size)
    return;
  v[index] = data;
  insertHeap(v, size, index);
  heapify(v, index, size);
}

int main(){
  int numOfNodes, numOfCommands;
  vector <int> nodes;

  cin >> numOfNodes;

  int size = numOfNodes + 1;
  nodes.resize(size + 1, 0);

  for(int i = 1; i < size; i++){
    cin >> nodes[i];
  }

  if(maxHeap(nodes, 1, size))
    cout << "This is a heap." << endl;
  else
    cout << "This is NOT a heap." << endl;
  
  for(int i = size / 2; i >= 1; i--){
    heapify(nodes, i, size);
  }

  cin >> numOfCommands;
  
  string temp;
  int data, index;
  for(int i = 0; i < numOfCommands; i++){
    cin >> temp;
    if(temp == "displayMax"){
      cout << display_max(nodes, size) << endl;
    } else if(temp == "insert"){
      cin >> data;
      insertNode(nodes, size, data);
    } else if(temp == "deleteMax"){
      deleteMax(nodes, size);
    } else if(temp == "delete"){
      cin >> data;
      deleteNode(nodes, size, data);
    } else if(temp == "display"){
      print(nodes, size);
    }else if(temp == "update"){
      cin >> index >> data;
      updateData(nodes, size, index, data);
    }
  }

  return 0;

}
