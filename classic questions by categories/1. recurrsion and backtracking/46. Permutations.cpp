/*
Description:
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/


/*
array -> generate all permutations
1. distinct ints

dfs + backtracking

inside dfs:

base case: depth = len(nums)

for int i = 0 to len(nums):
recurrsion

vector<bool> used, same size with nums, to keep tracks of the used elements
*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    void dfs(vector<int>& nums, int d, vector<bool>& used, vector<vector<int>>& ans, vector<int>& curr) {
        // base case:
        if(d == nums.size()) {
            ans.push_back(curr);
            return;
        }
        
        // recurrsive step
        for(int i = 0; i < nums.size(); ++i) {
            // check if the current element has been used
            if(used[i]) continue;
            used[i] = true;
            curr.push_back(nums[i]);
            dfs(nums,d+1,used,ans,curr);
            used[i] = false;
            curr.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used (nums.size(), false);
        dfs(nums,0,used,ans,curr);
        return ans;
    }
};