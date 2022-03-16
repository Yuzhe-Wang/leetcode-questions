/*
Description:
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/

// idea: binary search

// IMPORTAND: if condition: if(left <= right
// transition to the next iteration: left = mid + 1 & right = mid - 1


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // find the first occurrance
    int searchFirst(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left+right)/2;
        int result = -1;
        while(left <= right) {
            if(nums[mid] < target) {
                left = mid + 1;
            } else if(nums[mid] > target) {
                right = mid - 1;
            } else {
                // target == nums[mid], then we know the first will be on the left side of mid
                result = mid;
                right = mid - 1;
            }
             mid = (left+right)/2;
        }
        return result;
    }
    
    int searchLast(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left+right)/2;
        int result = -1;
        while(left <= right) {
            if(nums[mid] < target) {
                left = mid + 1;
            } else if(nums[mid] > target) {
                right = mid - 1;
            } else {
                // target == nums[mid], then we know the last will be on the right side of mid
                result = mid;
                left = mid + 1;
            }
             mid = (left+right)/2;
        }
        return result;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(searchFirst(nums,target));
        result.push_back(searchLast(nums,target));
        return result;
    }
};

/*
note that: 1. the array is sorted in non-decreasing order
2. runtime logn

idea: binary search
nums = [5,7,7,8,8,10], target = 8

three pointers left = 0, right = nums.size() - 1, mid = (left + right) /2;
mid < target, target is on the right side
mid > target, target is on the left side
mid == target, expand and find the range : left = mid, right = mid

*/
