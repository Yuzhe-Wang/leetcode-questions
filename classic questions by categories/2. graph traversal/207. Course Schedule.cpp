/*
Description:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/

/*
input: an array of pairs, b is the prerequisite of a
output: a boolean - if I can finish all courses

1. All the pairs prerequisites[i] are unique.

graph: every class can be a node, add edges according to the input
if there were no cycle in the graph, true

1. dfs on every node O((m+n)m) = O(n^2) where n is the number of edges/length of the input
2. topological sort, a variation of dfs, find a node with no outgoing edges, remove it and repeat
whenever you leave a node, never to return, label that as our last node O(n), go through all the nodes
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build the graph with an adjacency list
        adj = vector<vector<int>> (numCourses);
        for(const auto& c: prerequisites) {
            adj[c[1]].push_back(c[0]);
        }
            
        // define states: 0 = unvisited, 1 = visiting, 2 = visited/removed
        vector<int> states(numCourses, 0);

        for(int i = 0; i < numCourses; ++i) {
            if(dfs(i,states)) return false;
        }

        return true;
    }
private:
    vector<vector<int>> adj;
    bool dfs(int curr, vector<int>& states) {
        if(states[curr] == 1) return true; // cycle detected
        if(states[curr] == 2) return false; // cycle not detected
        
        states[curr] = 1;
        for(const int j: adj[curr]) {
            if(dfs(j,states)) return true;
        }
        states[curr] = 2;
        return false;
    }
};