/*Minimum Degree of a Connected Trio in a Graph
You are given an undirected graph.You are given an integer n which is the number of nodes in the graph and an array edges, where each edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi.
A connected trio is a set of three nodes where there is an edge between every pair of them.
The degree of a connected trio is the number of edges where one endpoint is in the trio, and the other is not.
Return the minimum degree of a connected trio in the graph, or -1 if the graph has no connected trios.
Constraints:
2 <= n <= 400
edges[i].length == 2
1 <= edges.length <= n * (n - 1) / 2
1 <= ui, vi <= n
ui != vi
There are no repeated edges.
Example:

Input: n = 6, edges = [[1, 2], [1, 3], [3, 2], [4, 1], [5, 2], [3, 6]]
Output : 3

Explanation : There is exactly one trio, which is[1, 2, 3].The edges that form its degree are bolded in the figure above.

Expected Time Complexity : O(n ^ 3)
*/

#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

int minTrioDegree(int n, vector<vector<int>> edges) {
    vector<vector<int>> adjList(n + 1); // just ignore the 0 index. nodes start at 1; 
    vector<vector<int>> trios;

    // building adjList 
    for (auto& edge : edges) {
        int node0 = edge[0];
        int node1 = edge[1];

        adjList[node0].push_back(node1);
        adjList[node1].push_back(node0);
    }

    // detecting trios 
    // iterating nodes in adjList 
    for (int i = 1; i <= n; i++) {
        // iterating neighbours of node i  
        for (int j = 0; j < (int)adjList[i].size(); j++) {
            // iterating the neighbours of a neighbour in adjList 
            int neighbour = adjList[i][j];
            for (int k = 0; k < (int)adjList[neighbour].size(); k++) {
                if (find(adjList[i].begin(), adjList[i].end(), adjList[neighbour][k]) != adjList[i].end()) {
                    // we have a trio 
                    vector<int> trio = { i, neighbour, adjList[neighbour][k] };
                    sort(trio.begin(), trio.end(), greater<int>());

                    if (find(trios.begin(), trios.end(), trio) == trios.end())
                        trios.push_back(trio);
                }
            }
        }
    }

    int min_trio_degree = n * (n - 1) / 2;
    if (trios.size() > 0) {
        for (auto& trio : trios) {
            int trio_degree = 0;
            for (int i : trio) {
                // check the neighbours of this  
                for (int neighbour : adjList[i]) {
                    if (find(trio.begin(), trio.end(), neighbour) == trio.end()) {
                        trio_degree++;
                    }
                }
            }

            if (trio_degree < min_trio_degree)
                min_trio_degree = trio_degree;
        }

        return min_trio_degree;
    }
    else
        return -1;
}