/*
Description:
Given a string s, find the length of the longest substring without repeating characters.
*/

// idea: use the sliding window technique to iterate through all possible substrings
// also use a set to check the duplicates

#include <iostream>
#include <string>
#include "math.h"
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // construct a set to check for duplicates
        set<char> mSet;
        
        // use the sliding window technique
        int left = 0;
        int right = 0;
        int length = s.length();
        int maxLength = 0;
        
        for(right = 0; right < length; ++right) {
            if(mSet.find(s[right]) == mSet.end()) {
                mSet.insert(s[right]);
                maxLength = max (maxLength, right - left + 1);
            } else {
                while(left <= right) {
                    mSet.erase(mSet.find(s[left]));
                    left ++;
                    if(mSet.find(s[right]) == mSet.end()) {
                        mSet.insert(s[right]);
                        maxLength = max (maxLength, right - left + 1);
                        break;
                    }
                }
            }
        }
        
        return maxLength;
    }
};