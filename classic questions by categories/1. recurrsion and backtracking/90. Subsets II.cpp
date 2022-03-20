/*
Description:
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

/*
array with duplicates -> all possible subsets
subset/combinations of length 0,1,2,3... len(nums)

for i = 0 to len(nums)
dfs()

1. nums may contain duplicates
2. solution cannot contain duplicate subsets

dfs + backtracking
sort the input
disallow same number on the same layer
generate combinations 

base case: if d == n

1,2,1
1,2
2,1

1,1,2
1,1 1,2 
2

*/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void dfs(vector<int>& nums, int n, int d, int s, vector<vector<int>>& ans, vector<int>& curr) {
        // base case:
        if(d == n) {
            ans.push_back(curr);
            return;
        }
        
        // recurrsive steps:
        for(int i = s; i < nums.size(); ++i) {
            if(i > s && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            dfs(nums,n,d+1,i+1,ans,curr);
            curr.pop_back();
        }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size(); ++i) {
            dfs(nums,i,0,0,ans,curr);
        }
        return ans;
    }
};