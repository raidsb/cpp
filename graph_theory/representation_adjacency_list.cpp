#include <iostream>
#include<list>

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

int main_representation_adjacency_list() {
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0, 4);
	g.addEdge(2, 1);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.printAdjList();
	return 0;
}