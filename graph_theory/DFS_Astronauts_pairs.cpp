/*
Astronaut Pairs
The member states of the UN are planning to send people to the moon. They want them to be from different countries. You will be given a list of pairs of astronaut ID's. Each pair is made of astronauts from the same country. Determine how many pairs of astronauts from different countries they can choose from.

Example
n = 4
astronauts = [1,2] [2,3]
There are 4 astronauts numbered 0 through 3. Astonauts grouped by country are [0] and [1,2,3]. There are 3 pairs to choose from [0,1], [0,2] and [0,3].

Input
Input contains the number N : denoting number of astronauts and and list L denoting the pairs of astronauts from the same country.
N = 5
vector<pair<int,int> > astronauts = {{0,1}, {2,3} , {0,4}};

Output
6

There are 6 ways to choose a pair (0,2) (0,3) (1,2) (1,3) (4,2) and (4,3) as astronauts (0,1,4) belong to country 1 and (2,3) belong to another.
*/
#include<list>
#include<vector>
using namespace std;

class Graph {
	list<int>* l;
	int V;
public:
	Graph(int v) {
		V = v;
		//Array of Linked List
		l = new list<int>[V];
	}

	void addEdge(int i, int j, bool bidir = true) {
		l[i].push_back(j);
		if (bidir) {
			l[j].push_back(i);
		}
	}
	int traverseHelper(int s, bool* visited) {
		visited[s] = true;
		int size = 1;

		//visit the neighbours of s and thier neighbours recursilvely
		for (int nbr : l[s]) {
			if (!visited[nbr]) {
				size += traverseHelper(nbr, visited);
			}
		}
		return size;
	}

	//DFS - Depth First Search O(V+E) Linear
	int countAstronauts() {
		bool* visited = new bool[V] {0};
		int ans = V * (V - 1) / 2; // we use the maximum possible edges between all nodes.

		// for each node, check what nodes can be visited. 
		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				int csize = traverseHelper(i, visited); 
				
				// remove the possible connections between visited. Q mark.
				ans -= (csize) * (csize - 1) / 2;
			}
		}
		return ans;
	}
};

int count_pairs(int N, vector<pair<int, int> > astronauts) {
	//complete this method
	Graph g(N);

	for (auto edge : astronauts) {
		g.addEdge(edge.first, edge.second);
	}

	return g.countAstronauts();
}