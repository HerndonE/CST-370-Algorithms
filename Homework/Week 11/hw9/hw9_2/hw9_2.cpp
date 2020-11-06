/*
 * Title: hw9_2.cpp
 * Abstract: A program that conducts the topological sorting
 * based on the Kahn’s algorithm covered in the class.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 11/12/2020
 */
#include<iostream>
#include<vector>
#include<queue>

using namespace std;


/*
Pseudo code from https://en.wikipedia.org/wiki/Topological_sorting#Kahn's_algorithm
while S is not empty do
    remove a node n from S
    add n to L
    for each node m with an edge e from n to m do
        remove edge e from the graph
        if m has no other incoming edges then
            insert m into S

if graph has edges then
    return error   (graph has at least one cycle)
else
    return L   (a topologically sorted order)
*/


void kahnsAglorithm(vector < vector < int > > & myVector, vector < int > indegree) {

  // Create an queue and enqueue
  // all vertices with indegree 0
  queue < int > q;

  for (int i = 0; i < indegree.size(); i++){
    if (indegree[i] == 0){
      q.push(i);
    }
  }

   // Initialize count of visited vertices
  int count = 0;

  // Create a vector to store
  // result (A topological
  // ordering of the vertices)
  vector < int > sorted;


  // One by one dequeue vertices
  // from queue and enqueue
  // adjacents if indegree of
  // adjacent becomes 0

  while (!q.empty()) {
    // Extract front of the queue
    // and add it to sort
    int top = q.front();
    q.pop();
    sorted.push_back(top);

    for (int i = 0; i < myVector[top].size(); i++) {
      if (--indegree[myVector[top][i]] == 0)
        q.push(myVector[top][i]);
    }
    count++;
  }

  // Check if there was a DAG or not
  if (count != myVector.size()) {
    cout << "No Order:";
    return;
  } else {
    cout << "Order:";
    for (int i = 0; i < sorted.size(); i++) {
      if (i != 0){
        cout << "->";
      }
      cout << sorted[i];
    }
  }
}

int main() {

  int vertices, edges, pointA, pointB;

  cin >> vertices >> edges;

  vector < vector < int >> myVector(vertices);
  vector < int > indegree(vertices, 0);

  for (int i = 0; i < edges; i++) {
    cin >> pointA >> pointB;
    indegree[pointB]++;
    myVector[pointA].push_back(pointB);
  }

  for (int i = 0; i < indegree.size(); i++) {
    cout << "In-degree[" << i << "]:" << indegree[i] << endl;
  }

  kahnsAglorithm(myVector, indegree);

  return 0;
}
