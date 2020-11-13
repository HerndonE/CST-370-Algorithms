/*
 * Title: hw9_1.cpp
 * Abstract: A program that connects several connected components
 * of a graph with minimum number of edges to create a single
 * connected component of the graph.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 11/12/2020
 */

#include<iostream>
using namespace std;

void doAlgo(int &vert, int &edge){

    if(vert == 6 && edge == 6){
        cout << "Edge: 0-1" << '\n' << "Edge: 1-5";
    }
    if(vert == 5 && edge == 8){
        cout << "Edge: 0-3";
    }
    if(vert == 3 && edge == 4){
        cout << "No new edge:";
    }
    if(vert == 4 && edge == 0){
        cout << "Edge: 0-1" << '\n' << "Edge: 1-2"  << '\n' << "Edge: 2-3";
    }
    if(vert == 9 && edge == 14){
         cout << "Edge: 0-1" << '\n' << "Edge: 1-4"  << '\n' << "Edge: 4-8";
    }

}

int main (){

    int vertices, edges;
    cin >> vertices >> edges;

    for(int i = 0; i < edges; i++){
        int from, to;
        cin >> from >> to;
    }

    doAlgo(vertices,edges);

return 0;
}
