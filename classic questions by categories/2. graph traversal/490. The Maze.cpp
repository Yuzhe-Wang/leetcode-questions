/*
Description:
There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return true if the ball can stop at the destination, otherwise return false.

You may assume that the borders of the maze are all walls (see examples).*/

/*
given a maze, determine if there is a path from the starting point to then goal
dfs/bfs
bfs

use a queue as the fringe, start by pushing the intial point into the fringe
while !queue.empty:
    expend the top element,check if it's the goal
    add all unvisited children into the fringe


*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<pair<int,int>> fringe;
        pair<int,int> s (start[0], start[1]);
        pair<int,int> d (destination[0], destination[1]);
        vector<vector<bool>> visited;
        for(auto i: maze) {
            vector<bool> temp (maze[0].size(), false);
            visited.push_back(temp);
        }
        
        fringe.push(s);
        
        // do bfs
        while(!fringe.empty()) {
            auto curr = fringe.front();
            fringe.pop();
            if(curr == d) {
                return true;
            }
            if(visited[curr.first][curr.second]) continue;
            getSuccessor(maze, curr, fringe, visited);
            visited[curr.first][curr.second] = true;
        }
        return false;
    }
    
private:
    void getSuccessor(vector<vector<int>>& maze, pair<int,int>& curr, queue<pair<int,int>>& fringe, vector<vector<bool>> visited) {
        // get all unvisited children and push them into the fringe
        // check all four directions
        int row = curr.first;
        int col = curr.second;
        // check top
        while(row > 0 && maze[row-1][col] != 1) {
            row --;
        }
        fringe.push(make_pair(row,col));
        
        // check left
        row = curr.first;
        col = curr.second;
        while(col > 0 && maze[row][col-1] != 1) {
            col --;
        }
        fringe.push(make_pair(row,col));
        
        // check bottom
        row = curr.first;
        col = curr.second;
        while(row < maze.size()-1 && maze[row+1][col] != 1) {
            row ++;
        }
        fringe.push(make_pair(row,col));
        
        
        // check right
        row = curr.first;
        col = curr.second;
        while(col < maze[0].size() - 1 && maze[row][col+1] != 1) {
            col ++;
        }
        fringe.push(make_pair(row,col));
    }
};