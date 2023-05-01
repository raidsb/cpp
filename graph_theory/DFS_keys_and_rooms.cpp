/*
Keys and Rooms
There are N rooms and you start in room 0. Each room has a distinct number in 0, 1, 2, ..., N - 1, and each room may have some keys to access the next room.
Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in[0, 1, ..., N - 1] where N = rooms.length.A key rooms[i][j] = v opens the room with number v.
Initially, all the rooms start locked(except for room 0).
You can walk back and forth between rooms freely.
Return true if and only if you can enter every room.

Constraints:
1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
The number of keys in all rooms combined is at most 3000.

Expected Time Complexity : O(N + E), where N is the number of rooms, and E is the total number of keys.
*/
#include<vector>
using namespace std;

// The dfs helper recursive function takes 4 args:
// x: the starting node at the current call.
// v: the graph represented as a vector of edges.
// visit: the vector of graph nodes to mark as visited once visited.
void dfs(int x, vector<vector<int>>& v, vector<int>& visit)
{
    // 1: set current node as visited.
    visit[x] = 1;
    
    // 2: for each node x neighbour its.
    for (auto itr : v[x])
    {
        // if neigbour node is not visited. call the recursive dfs function.
        if (visit[itr] == 0)
        {
            dfs(itr, v, visit);
        }
    }
}

// dfs main function. the one calling the recursive one.
bool canVisitAllRooms(vector<vector<int>> rooms) {
    int n = rooms.size();
    
    // create and set the visited vector.
    vector<int>visit(n);

    // calling the helper dfs for node 0.
    dfs(0, rooms, visit);

    // when dfs finished. check for each node if visited.
    for (int i = 0; i < n; i++)
    {
        // if one of them is not visited. return false and exit;
        if (!visit[i])
        {
            return false;
        }
    }

    // all rooms are visited. 
    return true;
}


