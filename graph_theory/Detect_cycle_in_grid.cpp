/*
Detect Cycles in Grid
Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.
A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value as the current cell.
Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.
Constraints:
m == grid.length
n == grid[i].length
1 <= m <= 500
1 <= n <= 500
grid consists only of lowercase English letters.

Expected Time Complexity: O(n*m)
*/
#include<vector>
using namespace std;

bool ans_in_grid;
int visit_in_grid[501][501], dis[501][501], dx_in_grid[4] = { 1,-1,0,0 }, dy_in_grid[4] = { 0,0,1,-1 };
void dfs_in_grid(int x, int y, int n, int m, int len, int pre, char ch, vector<vector<char>>& grid)
{
    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != ch)
    {
        return;
    }
    if (visit_in_grid[x][y])
    {
        if (abs(dis[x][y] - pre) >= 3)
        {
            ans_in_grid = true;
        }
        return;
    }
    visit_in_grid[x][y] = 1;
    dis[x][y] = len;
    for (int i = 0; i < 4; i++)
    {
        dfs_in_grid(x + dx_in_grid[i], y + dy_in_grid[i], n, m, len + 1, dis[x][y], ch, grid);
    }
}
bool containsCycle(vector<vector<char>> grid) {
    int n = grid.size(), m = grid[0].size();
    memset(visit_in_grid, 0, sizeof(visit_in_grid));
    memset(dis, 0, sizeof(dis));
    ans_in_grid = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit_in_grid[i][j])
            {
                dfs_in_grid(i, j, n, m, 1, 1, grid[i][j], grid);
            }
        }
    }
    return ans_in_grid;
}