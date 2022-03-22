/*
Description:
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        // build the graph with an adjacency list
        adj = vector<vector<int>> (numCourses);
        for(const auto& c: prerequisites) {
            adj[c[1]].push_back(c[0]);
        }
            
        // define states: 0 = unvisited, 1 = visiting, 2 = visited/removed
        vector<int> states(numCourses, 0);

        for(int i = 0; i < numCourses; ++i) {
            if(dfs(i,states,result)) return {};
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
private:
    vector<vector<int>> adj;
    bool dfs(int curr, vector<int>& states, vector<int>& result) {
        if(states[curr] == 1) return true; // cycle detected
        if(states[curr] == 2) return false; // cycle not detected
        
        states[curr] = 1;
        for(const int j: adj[curr]) {
            if(dfs(j,states,result)) return true;
        }
        states[curr] = 2;
        result.push_back(curr);
        return false;
    }
};