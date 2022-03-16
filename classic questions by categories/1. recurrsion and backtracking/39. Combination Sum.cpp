/*
Description:
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

// notes： numbers can be chosen for unlimited number of times
// idea: dfs + backtracking

/* layer of choices:
1. form the entire array
2. form the entire array
...

termination point: 1. the sum equals to target, store the combination
2. the sum is greater than the target, return
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int> >& result, int currSum, vector<int> oneSolution, set<vector<int> >& freq) {
        // base cases:
        if(currSum == target) {
            sort(oneSolution.begin(), oneSolution.end());
            if(freq.find(oneSolution) == freq.end()) {
                result.push_back(oneSolution);
                freq.insert(oneSolution);
            }
            return;
        }
        if(currSum > target) {
            return;
        }
        // recurrsion + backtracking
        for(int i = 0; i < candidates.size(); ++i) {
            int temp = candidates[i];
            oneSolution.push_back(temp);
            helper(candidates, target, result, currSum + temp, oneSolution, freq);
            oneSolution.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> oneSolution;
        int currSum = 0;
        set<vector<int> > freq;
        helper(candidates, target, result, currSum, oneSolution, freq);
        return result;
    }
};