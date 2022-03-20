/*
Description:
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

/*
array of unique elements -> return all subsets
1. no duplicate
subsets/combinations of 0,1,2,3 ... n elements

dfs + backtracking
length n
for i=0 to len(nums):
    dfs(nums,d,n,i,ans,curr)
dfs: base case if d == n
    recussive step: dfs(nums,d+1,n,i+1,ans,curr)
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    void dfs(vector<int>& nums, int d, int n, int s, vector<vector<int>>& ans, vector<int>& curr) {
        // base case
        if(d==n) {
            ans.push_back(curr);
            return;
        }
        
        // recurrsive steps
        for(int i = s; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            dfs(nums,d+1,n,i+1,ans,curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        for(int i = 0; i<= nums.size(); ++i) {
            dfs(nums,0,i,0,ans,curr);
        }
        return ans;
    }
};