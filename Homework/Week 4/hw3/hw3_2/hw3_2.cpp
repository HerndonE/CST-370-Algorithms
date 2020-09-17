/*
 * Title: hw3_2.cpp
 * Abstract: A program that converts a directed graph data from a
 * user into a corresponding adjacency list format
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 9/17/2020
 */

#include<iostream>

using namespace std;

int main() {

  int vertices = 0;
  int edges = 0;

  cin >> vertices >> edges;

  int directedGraph[vertices][vertices] = {0};

  int first = 0;
  int second = 0;

  for (int i = 0; i < edges; ++i) { //populate 2d array
    cin >> first >> second;
    directedGraph[first][second] = 1;
  }

  for (int i = 0; i < vertices; ++i) { //sort accordingly
    cout << i;
    for (int j = 0; j < vertices; ++j) {
      if (directedGraph[i][j] == 1) {
        cout << "->" << j;
      }
    }
    cout << endl;
  }

  return 0;
}
