#include<vector>
using namespace std;

/*
Find Center of Star Graph
There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.
You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.
Constraints:
3 <= n <= 10^5
edges.length == n - 1
edges[i].length == 2
1 <= ui, vi <= n
ui != vi
The given edges represent a valid star graph.
*/

int findCenter(vector<vector<int>>edges)
{
    int center1 = edges[0][0];
    int center2 = edges[0][1];

    for (int i = 1; i < sizeof(edges); i++) {
        if (edges[i][0] == center1)
            return center1;

        if (edges[i][0] == center2)
            return center2;

        if (edges[i][1] == center1)
            return center1;

        if (edges[i][1] == center2)
            return center2;
    }
}