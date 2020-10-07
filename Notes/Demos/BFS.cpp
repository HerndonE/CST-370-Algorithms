// A sample program to conduct the breadth first search (BFS). 
// Written by EIR and Dr. Byun for CST370.

// Input graph format:
//   - Number of vertices
//   - Number of edges
//   - Each edge info with a starting and an ending vertices.
// First Example
/* 
3 
2
0 1
1 2
*/

// Second example
/* 
5
4
0 1
0 2
2 3
3 4
*/

// Third example
/* 
5
10
0 1
1 0
0 4
4 0
1 4
4 1
1 2
2 1
2 4
4 2
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void read_graph(vector<vector<int>> & g)
{
    int num_of_vertices;
    cin >> num_of_vertices;
    
    // Adjust the size of graph vector to hold all vertices.
    g.resize(num_of_vertices);
    
    int num_of_edges;
    cin >> num_of_edges;

    int from;
    int to;
    
    for (int i = 0; i < num_of_edges; i++) 
    {
        cin >> from;
        cin >> to;
        g[from].push_back(to);
    }
}


void printGraph(vector<vector<int>> & g) 
{
    for (int i = 0; i < g.size(); i++) 
    {
        cout << i;
        for (int j = 0; j < g[i].size(); j++) 
        {
            cout << " -> " << g[i][j];
        }
        cout << endl;
    }
}


void bfs(vector<vector<int>> & g, int src) 
{
    queue<int> q;
	int count = 0;
	vector<int> mark(g.size(), 0);
    
	mark[src] = ++count;
    q.push(src);
    while (!q.empty()) 
    {
        int curr = q.front();
        q.pop();

        cout << "visiting: " << curr << endl;

        for (int i = 0; i < g[curr].size(); i++) 
        {
            int neighbor = g[curr][i];
            if(mark[neighbor] == 0) 
            {
				mark[neighbor] = ++count;
                q.push(neighbor);
            }
        }
    }

    cout << "\n==== Mark Array ==== " << endl;
	for (int i = 0; i < g.size(); i++)
	{
		cout << "Mark[" << i << "]: " << mark[i] << endl;
	}

    return;
}



int main()
{
    vector<vector<int>> graph;
    
    read_graph(graph);

    cout << "==== Printing Input Graph - Vertext By Vertex =====" << endl;
    printGraph(graph);
    
    int src = 0;
    cout << "\n==== BFS - Source Vertext: " << src << " =====" << endl;
    bfs(graph, src);

    return 0;
}
