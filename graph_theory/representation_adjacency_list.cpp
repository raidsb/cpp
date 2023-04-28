/*
There are two algorithms to traverse a graph BFS (Breadth First Search) and DFS (Depth First Search)
BFS:
	1- We use a queue. Start with the first node
	2- Print the node
	3- Add the neighbours of the visited node to the queue
	4- Remove the visited node
	5- what will come next is the the first neighbour in the queue since it is a queue (FIFO)

	Need to maintain another vector for visited. So if a node is connected by more than once and it is visited already, 
	then should mark this node as visited so it is not printed again

	The term level is used here.
	Firs level 0 is the level of the first node
	Level 1 is is the neighbours of the first node
	Level 2 is the neighbours of all neighbours of level 1
	Level 3 is the neighbours of all neighbous of level 2
	..

	Uses of BFS:
	1- We can use the BFS to find the smallest path to a node from root node.
	2- The first time a node is visited is actually using the shortest path because it is being visited first. This is marked by the visited array.
	3- If a node is visited again later it is actually using a longer path.
	
	Distance of a node from a starting node:
	The distance(node) = distance(parent) + 1

	To get the shortest path to a node:
	In finding the shortest path to a node. Use the BFS to get the shortest path. 
	Maintain a parent array that stores the parent of each node. Then at getting the path. 
	Start with the destination node and back track to source using the temp = current node parent in a loop.

	Notes:
	1- BFS is iterative algorithm whereas DFS is recursive algorithm
	2- BFS is maining using a queue whereas DFS using stack
	3- Complexity of BFS and DFS is O(V+e)
*/

#include <iostream>
#include<list>
#include<queue>

using namespace std;

class Graph {
private:
	// Number of vertices/nodes in the graph.
	int V;
	
	// An array of lists of int. the * is a pointer to list and this notation means defining an array of lists.
	list<int>* l; 
	
public: 
	// Constructor. v is the number of vertices.
	Graph(int v) {
		V = v;
		l = new list<int>[V]; // dynamic allocation of an array of lists: list<int>* l = new list<int>[V];
	}

	// Adding edges to the graph. in this data structure of storing graph (Adjacency list) you store the neighbours
	void addEdge(int i, int j, bool undir = true) {
		l[i].push_back(j);
		if (undir) {
			l[j].push_back(i);
		}
	}

	// Breadth first search.
	void bfs(int source, int dest = -1) {
		queue<int> q; // queue used to visit a node and store the neighbours to come back and traverse them.
		bool* visited = new bool[V] {0}; // need to maintain a visited-node array to mark if a node is already visited.
		int* dist = new int[V] {0}; // will hold the shortest distance of node from a source node.
		int* parent = new int[V] {-1}; // will hold the direct parent of each node.

		// push the fist node, the starting node.
		q.push(source);
		visited[source] = true;

		while (!q.empty()) {
			// Process the first node in the queue
			int f = q.front();
			cout << f << endl;
			q.pop(); // we got the first node in the queue already.

			// push the neighbours of current node inside q if they are not already visited.
			// for each neighbour of the current node
			for (auto& neighbour : l[f]) {
				// if this neighbour is not visited
				if (!visited[neighbour]) {
					q.push(neighbour);
					visited[neighbour] = true;

					// setting the direct parent of a node
					parent[neighbour] = f;

					// setting the distance of a node from a source node = the distance of the parent + 1
					dist[neighbour] = dist[f] + 1;
				}
			}
		}

		// printing the distance of each node from the given source.
		for (int i = 0; i < V; i++) {
			cout << "Shortest distance to " << i << " from the source node is " << dist[i] << endl;
		}

		// printing the path from a source to any destination.
		if (dest != -1) {
			int temp = dest;
			while (temp != source) {
				cout << temp << " -- ";
				temp = parent[temp];
			}
			cout << source << endl;
		}
	}

	void printAdjList() {
		for (int i = 0; i < V; i++) {
			cout << i << "-->";

			for (auto node : l[i]) {
				cout << node << ",";
			}
			cout << endl;
		}
	}
};

int main() { // main_representation_adjacency_list
	Graph g(7);
	g.addEdge(0,1);
	g.addEdge(0, 4);
	g.addEdge(2, 1);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(5, 6);
	
	// printing the adjacency list
	g.printAdjList();

	// breadth first search with source node is 1
	g.bfs(1);
	
	// breadth first search with printing the path from 1 to 6
	g.bfs(1, 6);

	return 0;
}