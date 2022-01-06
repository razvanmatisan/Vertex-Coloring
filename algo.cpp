#include "algo.h"
#include <iostream> 
#include <list>
#include <fstream>

using namespace std;

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) { 
    adj[v].push_back(w); 
    adj[w].push_back(v);
} 

void Graph::resetColors(int colors[]) {
    for (int i = 0; i < V; i++) {
        colors[i] = -1;
    }
}

void Graph::showColors(int color[], ofstream& fout) {
    fout << "Assigned Colors are: " << endl;
    for (int i = 0; i < V; i++)
        fout << color[i] << " ";
    fout << endl << endl;
}

bool Graph::isValid(int v, int color[], int c) {
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++) {
        if (color[*i] == c) {
            return false;
        }
    }
    return true;
}

bool Graph::graphColoring(int m, int color[], int vertex) {
    if (vertex == V)
        return true;

    for (int col = 0; col < m; col++) {   
        if (isValid(vertex, color, col)) {
            color[vertex] = col;
            if (graphColoring (m, color, vertex + 1) == true)
                return true;
                   
        color[vertex] = 0;
        
        }
    }
    
    return false;
}

void Graph::backtrackingColoring(ofstream& fout) {
    int color[V];
    resetColors(color);
    color[0]  = 0;

    int max = 1;
    for (int i = 0; i < V; i++)
        color[i] = -1;

    while (graphColoring(max, color, 0) == false) {
        max++;
    }

    fout << "/////////// For Backtracking Algorithm ///////////" << endl << endl;
    fout << "The algorithm used " << max << " colors!" << endl;

    showColors(color, fout);
}

void Graph::greedyColoring(ofstream& fout) { 
    int result[V];
    resetColors(result); 

    result[0]  = 0; 
  
    bool available[V]; 
    for (int cr = 0; cr < V; cr++) 
        available[cr] = false; 
   
    for (int u = 1; u < V; u++) {  
        list<int>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (result[*i] != -1) 
                available[result[*i]] = true; 
  
        int cr; 
        for (cr = 0; cr < V; cr++) 
            if (available[cr] == false) 
                break; 
  
        result[u] = cr; 
  
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (result[*i] != -1) 
                available[result[*i]] = false; 
    }

    fout << "/////////// For Greedy Algorithm ///////////" << endl << endl;   
  
    int max = 0;
    for (int u = 0; u < V; u++) {
        if (max < result[u]) {
            max = result[u];
        }
    }
    max++;

    fout << "The algorithm used " << max << " colors!" << endl;
    showColors(result, fout);   
}

