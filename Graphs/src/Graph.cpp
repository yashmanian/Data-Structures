#include "Graph.h"

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];	// Create V number of new lists in adj
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);	// add w to v's list
}

void Graph::BFS(int s)
{
	// Mark all vertices not visited
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	// Create queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	// Create list iterator i
	list<int>::iterator i;

	while(!queue.empty())
	{
		// Dequeue a vertex and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// Get adjacent vertices of dequeued vertex s.
		// If they are not visited, mark visited and add to queue

		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if(!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}

}