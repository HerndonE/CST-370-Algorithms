/*
 * Title: hw5_2.cpp
 * Abstract: A program that reads an input graph data from a user.
 * Then, it should present a path for the travelling salesman problem (TSP).
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 10/2/2020
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printpath(vector<int>& path)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
        cout << path[i] << "->";
    cout << endl;
}

  // Modified from https://www.geeksforgeeks.org/traveling-salesman-problem-tsp-implementation/
  // implementation of traveling Salesman Problem
int travllingSalesmanProblem(vector < vector < int > > graph,vector<int> &path, int startVert, int startPoint)
{
    // store all vertex apart from source vertex
    vector<int> vertex;
    for (int i = 0; i < startVert; i++)
        if (i != startPoint)
            vertex.push_back(i);

    // store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do {

        // store current Path weight(cost)
        int current_pathweight = 0;

        // compute current path weight
        int k = startPoint;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
            path.push_back(vertex[i]);
        }
        current_pathweight += graph[k][startPoint];

        // update minimum
        min_path = min(min_path, current_pathweight);





    } while (
        next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}


int main() {
  int startVert, startEdge, cost, startingPoint = 0;
  cin >> startVert >> startEdge;

  vector < int > path;

  vector < vector < int > > tspVector(startVert, vector < int > (startVert));

  int pointA, pointB;
  for (int i = 0; i < startEdge; i++) {
    cin >> pointA >> pointB >> cost;
    tspVector[pointA][pointB] = cost;
  }

  cin >> startingPoint;

  cost = travllingSalesmanProblem(tspVector,path, startVert,startingPoint);

  //display results
  cout << "Path:";
  if (cost == -1) {
    path.clear();
  }

//printpath(path);

  cout << "Cost:" << cost << endl;

  return 0;
}
