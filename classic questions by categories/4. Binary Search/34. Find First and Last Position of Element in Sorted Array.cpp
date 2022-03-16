/*
Description:
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/

// idea binary search
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        while(left <= right) {
            if(nums[mid] < target) {
                left = mid + 1;
                mid = (left + right) / 2;
            } else if(nums[mid] > target) {
                right = mid - 1;
                mid = (left + right) / 2;
            } else {
                left = mid;
                right = mid;
                while(left >=0 && nums[left] == target) {
                    left --;
                }
                result.push_back(left + 1);
                while(right < nums.size() && nums[right] == target) {
                    right ++;
                }
                result.push_back(right - 1);
                return result;
            }
        }
        result.push_back(-1);
        result.push_back(-1);
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
