/*
 * Title: hw7_3.cpp
 * Abstract: A program that implements the Depth-First Search (DFS) algorithm
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 10/22/2020
 */
#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

//References: https://www.geeksforgeeks.org/difference-between-bfs-and-dfs/
//            https://www.geeksforgeeks.org/associative-arrays-in-cpp/

void input(int & vertices, int & edges, map < int, int > & markArray, map < int, vector < int > > & graph) {

  int pointA;
  int pointB;

  cin >> vertices >> edges;

  for (int i = 0; i < edges; i++) {
    cin >> pointA >> pointB;
    graph[pointA].push_back(pointB);
    markArray[pointA] = 0;
  }
}

void dfs(map < int, vector < int > > & graph, map < int, int > & markArray, int vertex, int & count) {

  count++;
  markArray[vertex] = count;
  for (int v: graph[vertex]) {
    if (markArray[v] == 0) {
      dfs(graph, markArray, v, count);
    }
  }
}

void iterateDFS(map < int, vector < int > > & graph, map < int, int > & markArray) {
  map < int, vector < int > > ::iterator i;
  int count = 0;

  for (i = graph.begin(); i != graph.end(); i++) {
    if (markArray[i -> first] == 0) {
      dfs(graph, markArray, i -> first, count);
    }
  }
}

void print(map < int, int > & markArray) {

  map < int, int > ::iterator i;
  for (i = markArray.begin(); i != markArray.end(); i++) {
    cout << "Mark[" << i -> first << "]:" << i -> second << endl;

  }
}

int main() {
  int vertices;
  int edges;

  map < int, int > markArray;
  map < int, vector < int > > graph;

  input(vertices, edges, markArray, graph);
  iterateDFS(graph, markArray);
  print(markArray);

  return 0;
}
/*
ALGORITHM DFS(G)
   //Implements a depth-first search traversal of a given graph
   //Input: Graph G = <V, E>
   //Output: Graph G with its vertices marked with consecutive integers
   //        in the order they are first encountered by the DFS traversal
  mark each vertex in V with 0 as a mark of being "unvisited"
  count ←0
  for each vertex v in V do
      if v is marked with 0
          dfs(v)


 Function dfs(v)
 //visits recursively all the unvisited vertices connected to vertex v
 //by a path and numbers them in the order they are encountered
 //via global variable count
 count ←count + 1
 mark v with count
 for each vertex w in V adjacent to v do
     if w is marked with 0
         dfs(w)

*/
