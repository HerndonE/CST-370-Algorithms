/*
 * Title:hw7_3.cpp
 * Abstract: This program conducts the DFS for an input graph and 
          displays the mark array.
 * Author: XXXX
 * ID: XXXX
 * Date: MM/DD/YYYY
 */

#include <iostream>
#include <vector>
#include <algorithm>    // For sort() of a vector.
using namespace std;

int counter = 0;

int read_graph(vector<vector<int>> & graph)
{
    int num_of_vertices;
    cin >> num_of_vertices;
    
    // Adjust the size of graph vector to hold all vertices.
    graph.resize(num_of_vertices);
    
    int num_of_edges;
    cin >> num_of_edges;

    int from;
    int to;
    
    for (int i = 0; i < num_of_edges; i++) 
    {
        cin >> from;
        cin >> to;
        graph[from].push_back(to);
    }
    
    // Sort vectors of neighbors to follow the convention of alphabetical order.
    for (int i = 0; i < graph.size(); i++) 
    {
        sort(graph[i].begin(), graph[i].end());
    }
    
    return num_of_vertices;
}


void DFS(vector<vector<int>> & graph, int v, int mark[])
{
    counter++;
    mark[v] = counter;    
    
    for (int i = 0; i < graph[v].size(); i++) 
    {
        int neighbor = graph[v][i];
        if(mark[neighbor] == 0)
        {
            DFS(graph, neighbor, mark);
        }
    }
}


int main()
{
    vector<vector<int>> graph;
    
    int numOfVertices = read_graph(graph);

    // Initialize the mark array
    int mark[numOfVertices];
    for(int i = 0; i < numOfVertices; i++)
    {
        mark[i] = 0;
    }
    
    for(int i = 0; i < numOfVertices; i++)
    {
        if (mark[i]== 0)
        {
            DFS(graph, i, mark);
        }
    }
    
    for(int i = 0; i < numOfVertices; i++)
    {
        cout << "Mark[" << i << "]: " << mark[i] << endl;
    }
    
    return 0;
}

