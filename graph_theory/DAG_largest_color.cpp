/*
Largest Color Value in a Directed Graph
There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
Constraints:

n == colors.length
m == edges.length
1 <= n <= 10^5
0 <= m <= 10^5

colors consists of lowercase English letters.
0 <= aj, bj < n
Input : n = 5 , colors = "abaca", edges =  {{0,1},{0,2},{2,3},{3,4}}

Output : 3
*/
#include<vector>
#include<string>
#include<queue>

using namespace std;

int largestPathValue(string colors, vector<vector<int>> edges) {
    int  n = colors.size();
    vector<vector<int>>cnt(n, vector<int>(26));
    vector<vector<int>>v(n + 1);
    vector<int>in(n + 1);
    for (int i = 0; i < edges.size(); i++)
    {
        int x = edges[i][0], y = edges[i][1];
        v[x].push_back(y);
        in[y]++;
    }
    queue<int>q;
    for (int i = 0; i < n; i++)
    {
        if (!in[i])
        {
            q.push(i);
            cnt[i][colors[i] - 'a'] = 1;
        }
    }
    int ans = 0;
    vector<int>topo;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        topo.push_back(x);
        for (int i = 0; i < 26; i++)
        {
            ans = max(ans, cnt[x][i]);
        }
        for (auto itr : v[x])
        {
            for (int i = 0; i < 26; i++)
            {
                cnt[itr][i] = max(cnt[itr][i], cnt[x][i] + (colors[itr] - 'a' == i));
            }
            in[itr]--;
            if (in[itr] == 0)
            {
                q.push(itr);
            }
        }
    }
    return topo.size() == n ? ans : -1;
}