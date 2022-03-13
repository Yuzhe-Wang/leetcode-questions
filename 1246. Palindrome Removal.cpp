/* 
Description:
Given an integer array arr, in one move you can select a palindromic subarray arr[i], arr[i+1], ..., arr[j] where i <= j, and remove that subarray from the given array. Note that after removing a subarray, the elements on the left and on the right of that subarray move to fill the gap left by the removal.

Return the minimum number of moves needed to remove all numbers from the array.
*/

/*
idea: dynamic programming
bitewise decision: how do we deal with the subarray from index i to index j
value stored in each cell: the min # of moves to remove all the # in the subarray from index i to index j
base cases: dp[i][i] = 1; 
            dp[i][i+1] = 1 if arr[i] == arr[i+1]
                       = 2 else
transition: 1. treat arr[i] and arr[j] as a pair if they match
                dp[i][j] = 0 + dp[i+1][j-1] if arr[i] == arr[j]
            2. find an index between i and j to break into two subarrays, and deal with them seperatly (k can eaqual to i and k+1 can equal to j)
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    
    int minimumMoves(vector<int>& arr) {
        
        int size = arr.size();
        vector<vector<int> > dp(size);
        for(int i = 0; i < size; ++i) {
            dp[i] = vector<int>(size, 0);
        }
        
        for(int i = size - 1; i >=0; --i) {
            for(int j = 0; j < size; ++j) {
                if(i == j) {
                    dp[i][j] = 1;
                }
                if(i == j - 1) {
                    if(arr[i] == arr[j]) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 2;
                    }
                }
                if(i < j - 1) {
                    // choices of pairing i and j
                    int pairing = INT_MAX;
                    if(arr[i] == arr[j]) {
                        pairing = 0 + dp[i+1][j-1];
                    }
                    
                    // split in the middle
                    int spliting = INT_MAX;
                    for(int k = i; k < j; ++k) {
                        spliting = min(spliting, dp[i][k] + dp[k+1][j]);
                    }
                    
                    dp[i][j] = min(pairing, spliting);
                }
            }
        }
        return dp[0][size-1];
    }
};
