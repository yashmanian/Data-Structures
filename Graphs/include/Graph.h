#include <iostream>
#include <list>

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

// Graph class
class Graph
{
private:
	int V; 	// Number of Vertices
	list<int> *adj;	// Pointer to an array containing adjacency list
public:
	Graph(int V); 	// Constructor
	void addEdge(int v, int u);	// Function to add edges
	void BFS(int s); 	// Prints Breadth first traversal from a given source s
	void DFS(int v);	// Prints Depth first traversal from a given source v
	void DFSUtil(int v, bool visited[]); // Recursive function to be called in DFS
};


#endif