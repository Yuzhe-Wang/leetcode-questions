/*
Description:
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/

// idea: bottom up dynamic programming, intialize the dp with an additional column and row of 0 because any string has longest common subsequence of length 0 with an empty string

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp;
        for(int i = 0; i < text1.length() + 1; ++i) {
            vector<int> temp (text2.length() + 1, 0);
            dp.push_back(temp);
        }
        
        for(int i = text1.length() - 1; i >=0; --i) {
            for(int j = text2.length() - 1; j >=0; --j) {
                if(text1[i] == text2[j]) {
                    dp[i][j] = dp[i+1][j+1] + 1;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};