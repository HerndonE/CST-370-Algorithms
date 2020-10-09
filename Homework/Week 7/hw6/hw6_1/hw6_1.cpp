/*
 * Title: hw6_1.cpp
 * Abstract: A program that conducts the BFS traversal of a graph and
 * displays city names in the range of hop(s) from a starting city.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 10/8/2020
 */

#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {

  int numCitiesVert;
  vector < string > cities;
  map < string, int > visited;

  cin >> numCitiesVert; //input

  for (int i = 0; i < numCitiesVert; i++) {
    string element;
    cin >> element;
    visited.insert({
      element,
      -1
    });
    cities.push_back(element);
  }

  int numCitiesEdge;
  string sourceCity;
  string destinationCity;
  unordered_map < string, vector < string >> graph;

  cin >> numCitiesEdge;

  for (int i = 0; i < numCitiesEdge; i++) {
    cin >> sourceCity >> destinationCity;
    graph[sourceCity].push_back(destinationCity);
  }

  string startingCity;
  int hops = 0;

  cin >> startingCity >> hops;

  queue < string > q;
  q.push(startingCity);
  visited.find(startingCity) -> second = 0;
  vector < int > amount;
  int replaceHops = 0;
  int counter = 0;
  map < string, int > results;

  sort(cities.begin(), cities.end());
  while (!q.empty()) //bfs
  {

    startingCity = q.front();
    results.insert({
      startingCity,
      visited[startingCity]
    });
    for (string neighbor: graph[startingCity]) {

      if (visited[neighbor] == -1) {
        visited[neighbor] = visited[startingCity] + 1;
        q.push(neighbor);
      }
    }
    q.pop();
  }

  for (auto itr = results.begin(); itr != results.end(); ++itr) { //display results
    if (itr -> second > hops) {
      continue;
    }
    cout << itr -> first << ": " << itr -> second << endl;
  }

  return 0;
}
