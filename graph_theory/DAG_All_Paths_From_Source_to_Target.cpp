/*
All Paths From Source to Target
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1, and return them in any order.
The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

Constraints:
n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n

graph[i][j] != i (i.e., there will be no self-loops).
The input graph is guaranteed to be a DAG.
Sample Input :
[ [1,2],
  [3],
  [3],
  [] ]
Sample Output :
[ [0,1,3],
  [0,2,3] ]
*/
#include<vector>
using namespace std;

// The recursive dfs
// arguments:
// x the current node to process
// v the graph as vector of edges
// n number of edges given 
// vec stack to store the current node to come back to it
// ans vector of possible pathes
void dfs(int x, vector<vector<int>>& v, int n, vector<int>& vec, vector<vector<int>>& ans)
{
    // stack to push the current visited
    vec.push_back(x);
    
    // if current node equals the last one in graph push back to stack
    if (x == n - 1)
    {
        ans.push_back(vec);
    }

    // for each neighbour in the graph call the dfs
    for (auto itr : v[x])
    {
        dfs(itr, v, n, vec, ans);
    }

    // once finished pop last
    vec.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> graph) {
    // get number of given graph. the number of nodes
    int n = graph.size();
    
    // holding possiple answers (possible pathes)
    vector<vector<int>>ans;
    
    // stack holding visited to come back to it
    vector<int>v;

    // calling the recursive dfs
    dfs(0, graph, n, v, ans);

    // return the possible pathes
    return ans;
}