/*
Cycle Detection in Undirected Graph
Given a undirected graph having n nodes, and an array of edges where edges[i] = [ui, vi] is a bidirectional edge between node ui and node vi .
Find whether the graph contains a cycle or not, return true if the cycle is present else return false.

Constraints:
3 <= n <= 10 ^ 5
2 <= edges.length <= 10 ^ 5
1 <= ui, vi <= n

Nodes are numbered 1 to n
Graph may or may not be connected
Input : n = 5, edges = { {1,  2}, {1, 3}, {2, 3}, {1,  4}, {4, 5} }
Output: true
*/
#include<vector>
using namespace std;

int flag;
void dfs(int x, int p, vector<int>& col, vector<vector<int>>& v)
{
    col[x] = 1;
    for (auto itr : v[x])
    {
        if (itr == p)
        {
            continue;
        }
        if (col[itr] == 1)
        {
            flag = 1;
        }
        if (col[itr] == -1)
        {
            dfs(itr, x, col, v);
        }
    }
    col[x] = 2;
}
bool solve(int n, vector<vector<int> > edges) {
    vector<vector<int>>v(n + 1);
    flag = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int x = edges[i][0], y = edges[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int>col(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (col[i] == -1) {
            dfs(i, 0, col, v);
        }
    }
    return flag == 1;
}