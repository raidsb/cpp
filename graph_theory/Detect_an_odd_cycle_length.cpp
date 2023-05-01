/*
Detecting an Odd Length Cycle
Given an undirected graph as an adjacency list, return whether the graph has an odd length cycle.

Constraints:
n, m ≤ 250 where n and m are the number of rows and columns in graph

Input
graph = [
   [1, 2, 3],
   [0, 2],
   [0, 1, 3],
   [0, 2]
]

Output
true

Explanation
One odd length cycle would be 0 -> 2 -> 1 -> 0

Expected  Time Complexity: O(n+m)
*/

#include<vector>
#include<queue>
using namespace std;

bool solve_detect_odd_cycle(vector<vector<int>> graph)
{
    int n = graph.size(), m = graph[0].size();
    vector<int>col(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        if (col[i] == -1)
        {
            queue<int>q;
            q.push(i);
            col[i] = 0;
            while (q.size())
            {
                int x = q.front();
                q.pop();
                for (auto itr : graph[x])
                {
                    if (col[itr] == -1)
                    {
                        col[itr] = col[x] ^ 1;
                        q.push(itr);
                    }
                    else {
                        if (col[itr] == col[x])
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}