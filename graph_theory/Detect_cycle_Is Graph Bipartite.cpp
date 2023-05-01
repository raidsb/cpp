/*
Is Graph Bipartite?
Given an undirected graph with n nodes, where each nodes is numbered 0 to  n-1.
You are given a 2D array, where for each v in graph[u] there is an undirected edge between node u and v.
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
Return whether Graph is Bipartite or not.

Constraints:
1 <= n <= 100

Example :
Input:
graph = {{1,2,3},{0,2},{0,1,3},{0,2}}

Output:
false

Explanation:
There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.

Expected Time Complexity: O(n+m), where m represent number of edges.
*/
#include<vector>
#include<queue>
using namespace std;

bool isBipartite(vector<vector<int>> graph) {
    int n = graph.size();
    vector<int> colors(n, 0);
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (colors[i]) continue;

        colors[i] = 1;
        q.push(i);

        while (!q.empty()) {
            int temp = q.front();

            for (auto neighbor : graph[temp]) {

                // Color neighbor with opposite color
                if (!colors[neighbor]) {
                    colors[neighbor] = -colors[temp];
                    q.push(neighbor);
                }

                // If the neighbor has the same color - can't bipartite.
                else if (colors[neighbor] == colors[temp]) {
                    return false;
                }
            }
            q.pop();
        }
    }
    return true;
}