/*
Course Schedule II
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair[0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses.If there are many valid answers, return lexicographically smallest of them.If it is impossible to finish all courses, return an empty array.

Constraints:
1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)

prerequisites[i].length == 2
0 <= ai, bi < numCourses
	ai != bi
	All the pairs[ai, bi] are distinct.
	Expected Time Complexity : O(V + E) where V represents the number of vertices and E represents the number of edges.
*/
#include<vector>
using namespace std;

bool canFinish(vector<vector<int>> prerequisites, int n) {
    vector<vector<int>> G(n);
    vector<int> degree(n, 0), bfs;
    for (auto& e : prerequisites)
        G[e[1]].push_back(e[0]), degree[e[0]]++;
    for (int i = 0; i < n; ++i) if (!degree[i]) bfs.push_back(i);
    for (int i = 0; i < bfs.size(); ++i)
        for (int j : G[bfs[i]])
            if (--degree[j] == 0) bfs.push_back(j);
    return bfs.size() == n;
}