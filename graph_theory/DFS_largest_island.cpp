/*
Largest Island
You are given a m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.

Sample Input
grid = [
 [1, 0, 0, 1, 0],
 [1, 0, 1, 0, 0],
 [0, 0, 1, 0, 1],
 [1, 0, 1, 1, 1],
 [1, 0, 1, 1, 0]
]

Sample Output
8

Explanation
There are 4 islands (connected components) of sizes 2,1,8,2 out of which 8 is largest.
Expected Time Complexity: O(n*m)

it is BFS not DFS
*/
#include<vector>
#include<queue>
using namespace std;

// possible x and y coordinates values. 
// we will use these coordinates values to visited the nearby (x, y) locations in the grid
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

int maxAreaOfIsland(vector<vector<int>> grid) {
    // initializing n, the starting point of x coordinate. 
    // initializing m, the starting point of y coordinate.
    // initializing ans, will hold the final answer value.
    int n = grid.size(), m = grid[0].size(), ans = 0;
    
    // no grid, no islands. 
    if (n == 0)
    {
        return ans;
    }

    // creating and setting a grid of visited cells in the grid. 
    vector<vector<int>>visit(n, vector<int>(m));

    // iterate cell by cell (with checking the visited)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // will count the land for the current cell and neighbours
            int cnt = 0;

            // if the current cell is 1 (land) and not visited before
            if (grid[i][j] == 1 && !visit[i][j])
            {
                // add current land to count 
                cnt++;

                // push the current coordinates to queue
                queue<pair<int, int>>q;
                q.push({ i,j });
                
                // set the current coordinates to visited
                visit[i][j] = 1;

                // now while queue is not empty..check the neighbours using the defined possible coordinates.
                while (!q.empty())
                {
                    // get the first in queue
                    pair<int, int>p = q.front();
                    q.pop();

                    // now for each possible coordinates. the k will iterate over both possible x and y coordinates 
                    for (int k = 0; k < 4; k++)
                    {
                        // set the new x and y coordinates
                        int pos = p.first + dx[k], pos1 = p.second + dy[k];
                        
                        // if the new position is in grid range and not visited and land
                        if (pos >= 0 && pos1 >= 0 && pos < n && pos1 < m && !visit[pos][pos1] && grid[pos][pos1] == 1)
                        {
                            // set the new position as visited
                            visit[pos][pos1] = 1;
                            
                            // increase land count
                            cnt++;

                            // push the new position to queue to explore it
                            q.push({ pos,pos1 });
                        }
                    }
                }

                // check if island is larger than current max
                ans = max(ans, cnt);
            }
        }
    }
    return ans;
}