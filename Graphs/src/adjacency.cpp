#include <bits/stdc++.h>
using namespace std;

// Function to add an edge in an undirected graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Print Adjacency list
// void printGraph(vector<int> adj[], int V)
// {
//     for (int i = 0; i<V; ++i)
//     {
        
//     } 
// }

// Driver code
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
}