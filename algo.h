#ifndef ALGO_H
#define ALGO_H

#include <iostream> 
#include <list>
#include <fstream>

using namespace std; 

class Graph { 
    int V; 
    list<int> *adj;
public:
    Graph(int V);
  
    void addEdge(int v, int w);

    void resetColors(int colors[]);

    void showColors(int color[], ofstream& fout);

    bool graphColoring(int m, int color[], int vertex);

    bool isValid(int v, int color[], int c);
  
    void greedyColoring(ofstream& fout);

    void backtrackingColoring(ofstream& fout);
}; 

#endif