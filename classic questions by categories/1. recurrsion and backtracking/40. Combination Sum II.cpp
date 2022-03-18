/*
Description:
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
*/
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void combinations(int ind,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds) {
        if(target==0) {
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<arr.size();i++) {
            if(i>ind&& arr[i]==arr[i-1]) continue;  // if next element is same  ;
            
            if(arr[i]>target)break;
            
            //pick condition ..
            ds.push_back(arr[i]);
            combinations(i+1,target-arr[i],arr,ans,ds); 
            ds.pop_back(); // backtrack and pop the element
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        combinations(0,target,candidates,ans,ds);
        return ans;
    }
};