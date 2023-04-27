#include<iostream>
#include<string>
#include<list>
#include<unordered_map>

using namespace std;

// main data is strings (cities for example)

class Node {
public:
	string name;
	list<string> neighbours;
	Node(string given_name) {
		this->name = given_name;
	}
};

class Graph {
private:
	unordered_map<string, Node*> graph_map; // hash table. in each item the key is the string name of the node and the second is an array of nodes or just a pointer to a node

public: 
	Graph(vector<string> nodes_names) {
		for (auto& n : nodes_names) {
			this->graph_map[n] = new Node(n);
		}
	}

	void add_edge(string x, string y, bool undir = false) {
		graph_map[x]->neighbours.push_back(y);

		if (undir) {
			graph_map[y]->neighbours.push_back(x);
		}
	}

	void printAdjacencyList() {
		for (auto& node : graph_map) {
			string node_name = node.first;
			cout << "node_name: " << node_name << ": ";
			Node* node_obj = node.second;

			for (string neighbour : node_obj->neighbours) {
				cout << neighbour << ",";
			}
			cout << endl;
		}
	}
};

int main() {
	vector<string> cities = { "Jerusalem", "Haifa", "Yafa", "Akka" };
	Graph g(cities);
	g.add_edge("Jerusalem", "Haifa");
	g.add_edge("Yafa", "Akka");
	g.add_edge("Jerusalem", "Yafa");
	g.add_edge("Akka", "Jerusalem");
	g.printAdjacencyList();

	return 0;
}