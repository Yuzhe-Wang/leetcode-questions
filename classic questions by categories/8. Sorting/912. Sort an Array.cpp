/*
Description:
Given an array of integers nums, sort the array in ascending order.
*/

// idea: implement quick sort
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    int partition(vector<int>& nums, int low, int high) {
        // dig a hole
        int index=(rand()%(high+1-low))+low;
        swap(nums[low],nums[index]);
        int pivot = nums[low];
        while(low < high) {
            // find the first element on pivot's right that is less than pivot
            while(low < high && nums[high] >= pivot) high--;
            nums[low] = nums[high];
            // then find the first element on pivot's left that is greater than the pivot
            while(low < high && nums[low] <= pivot) low++;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }
    
    void quicksort(vector<int>& nums, int low, int high) {
        if(low < high) {
            int mid = partition(nums,low,high);
            quicksort(nums,low,mid-1);
            quicksort(nums,mid+1,high);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size()-1);
        return nums;
    }
};