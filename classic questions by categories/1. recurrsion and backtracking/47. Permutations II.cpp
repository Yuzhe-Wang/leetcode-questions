/*
Description:
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
*/

/*
array -> generate all uique permutations
1. input may contain duplicates

dfs + backtracking -> generate permutations
used, same size with the input, vector of bool

base case: d == len(nums)
recurrsive step: call dfs, disallow same number on the same level

sort input + skip same numbers
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int d, vector<bool>& used) {
        // base case
        if(d == nums.size()) {
            ans.push_back(curr);
            return;
        }
        
        // recurrsive steps
        for(int i = 0; i < nums.size(); ++i) {
            // for permutations, for numbers of the same value, we cannot skip the previous ones and use the later ones
            // because we will systamically do the permutation in such a way: for nums of the same values, we pick the ones with smaller indices first
            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            if(used[i]) continue;
            curr.push_back(nums[i]);
            used[i] = true;
            dfs(nums,ans,curr,d+1,used);
            curr.pop_back();
            used[i] = false;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used (nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums,ans,curr,0,used);
        return ans;
    }
};