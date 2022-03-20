/*
Description:
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

/*
array -> generate all the combinations
1. unique combinations
2. same number can be chosen multiple times

dfs + backtracking
for i = s to len(candidates):
curr.push
dfs(next layer i will start from i again)
curr.pop
*/

*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
class Solution {
public:
    
    void dfs(vector<int>& candidates, int target, int s, vector<vector<int>>& ans, vector<int>& curr) {
        // base case
        if(target <= 0) {
            if(target == 0) {
                ans.push_back(curr);
            }
            return;
        }
        
        // recurrsive steps
        for(int i = s; i < candidates.size(); ++i) {
            curr.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, ans, curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(candidates, target, 0, ans, curr);
        return ans;
    }
};