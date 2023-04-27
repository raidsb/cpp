/* Maximal Network Rank
There is an infrastructure of n cities with some number of roads connecting these cities.Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.
The network rank of two different cities is defined as the total number of directly connected roads to either city.If a road is directly connected to both cities, it is only counted once.
The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.
Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.
Constraints:
2 <= n <= 100
0 <= roads.length <= n * (n - 1) / 2
roads[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
Each pair of cities has at most one road connecting them.

Example :
Input: n = 4, roads = [[0, 1], [0, 3], [1, 2], [1, 3]]
Output : 4

Explanation : The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to either 0 or 1. The road between 0 and 1 is only counted once.

Expected Time Complexity : O(n ^ 2)
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maximalNetworkRank(int n, vector<vector<int>> roads) {
    unordered_map<int, vector<int>> adjList;

    for (auto& edge : roads) {
        cout << "edge: " << edge[0] << "," << edge[1] << endl;

        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    int maximal_network_rank = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int i_rank = adjList[i].size();
                int j_rank = adjList[j].size();

                cout << "i rank of " << i << " is " << i_rank << endl;
                cout << "j rank of " << j << " is " << j_rank << endl;

                vector<int> temp_connections = adjList.at(i);
                if (find(temp_connections.begin(), temp_connections.end(), j) != temp_connections.end())
                    i_rank--;

                if (maximal_network_rank < i_rank + j_rank)
                    maximal_network_rank = i_rank + j_rank;
            }
        }
    }

    return maximal_network_rank;
}