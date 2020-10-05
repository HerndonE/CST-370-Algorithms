/*
 * Title: hw5_2.cpp
 * Abstract: Given input graph data, this 
             program solves a TSP by finding
             the least expensive path.
 * Author: XXXX
 * ID: XXXX
 * Date: MM/DD/YYYY
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    
    // Retrieve Edge Data (Store Path as key and cost as value)
    unordered_map<string, int> edgeData;
    for (int i = 0; i < edges; i++) {
        string sVertex, dVertex;
        int cost;
        cin >> sVertex >> dVertex >> cost;
        
        edgeData[sVertex + dVertex] = cost;
    }
    
    int startVertex;
    cin >> startVertex;
    
    // Setup Perumutation Array to Create Permutations
    int permutation[vertices - 1];
    int l = 0;
    for (int j = 0; j < vertices; j++) {
        if (j != startVertex) {
            permutation[l] = j;
            l++;
        }
    }
    
    // Setup Vectors of All Possible Permutations
    vector<vector<int>> permutations;
    do {
        vector <int> tempArr;
        
        // Add Current Permutation + Start Vertex to Vector
        tempArr.push_back(startVertex);
        for (int k = 0; k < vertices - 1; k++) {
            tempArr.push_back(permutation[k]);
        }
        tempArr.push_back(startVertex);
        
        permutations.push_back(tempArr);
    } while (next_permutation(permutation, permutation + (vertices - 1)));
    
    // Find Least Expensive Permutation (Path)
    int minCost = INT_MAX;
    int bestPath = -1;
    for (int m = 0; m < permutations.size(); m++) {
        int currentCost = 0;
        
        // Calculate Path Cost for Each Permutation (Skip those Not Possible)
        for (int n = 0; n < vertices; n++) {
            string edgePath = to_string(permutations[m][n]) + to_string(permutations[m][n + 1]);
            
            if (edgeData.count(edgePath) > 0) {
                currentCost += edgeData[edgePath];
            } else {
                currentCost = INT_MAX;
                break;
            }
        }
        
        // Save Info if Cheapest Path
        if (currentCost < minCost) {
            minCost = currentCost;
            bestPath = m;
        }
    }
    
    // Output Results
    cout << "Path:";
    if (bestPath != -1) {
        for (int p = 0; p < permutations[bestPath].size(); p++) {
            if (p > 0) {
                cout << "->";
            }
            
            cout << permutations[bestPath][p];
        }
    } else {
        minCost = -1;
    }
    
    cout << "\nCost:" << minCost << endl;
    
    return 0;
}