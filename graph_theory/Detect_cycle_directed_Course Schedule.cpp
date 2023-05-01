/*
Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Constraints:
1 <= numCourses <= 10^5
0 <= prerequisites.length <= 5000

prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
Sample input :  numCourses = 2  prerequistics : [[1,0]]
Sample Output : true
*/
#include<vector>;
using namespace std;

bool ans;
void dfs(int x, vector<vector<int>>& v, int col[])
{
    col[x] = 1;
    for (auto itr : v[x])
    {
        if (!col[itr])
        {
            dfs(itr, v, col);
        }
        else
        {
            if (col[itr] == 1)
            {
                ans = false;
            }
        }

    }
    col[x] = 2;
}

/* has problem with compiling, but working in the course.
bool canFinish(vector<vector<int>> c, int n) {
    ans = true;
    vector<vector<int>>v(n);
    for (int i = 0; i < c.size(); i++)
    {
        v[c[i][0]].push_back(c[i][1]);
    }

    int col[n];
    memset(col, 0, sizeof(col));
    for (int i = 0; i < n; i++)
    {
        if (!col[i])
        {
            dfs(i, v, col);
        }
    }
    return ans;
}
/**/