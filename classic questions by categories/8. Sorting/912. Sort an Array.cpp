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
    void bubblesort(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n - 1; ++j) {
                if(nums[j] > nums[j+1]) {
                    swap(nums[j],nums[j+1]);
                }
            }
        }
    }
    
    void heapify(vector<int>& nums, int i, int n) {
        // recursivly heapfiy the tree starting with root nums[i]
        int greatest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        // find and swap with the greater child
        if(left < n && nums[left] > nums[greatest]) {
            greatest = left;
        }
        if(right < n && nums[right] > nums[greatest]) {
            greatest = right;
        }
        if(greatest != i) {
            swap(nums[i], nums[greatest]);
            heapify(nums,greatest,n);
        }
    }
    
    void heapsort(vector<int>& nums, int n) {
        // build a heap (max heap)
        // start with index n/2 -1, because all later nodes are leaf nodes
        for (int i = n/2 - 1; i >=0; --i) {
            heapify(nums, i, n);
        }
        // sort with the heap
        for(int j = n - 1; j >=0; j--) {
            int m = nums[0];
            swap(nums[0], nums[j]);
            heapify(nums,0,j);
        }
    }
    
    void merge(vector<int>& nums, int left, int mid, int right) {
        // merge two already sorted array
        if(nums[mid] < nums[mid + 1]) {
            return;
        }
        int a = left;
        int b = mid + 1;
        while(a <= mid && b <= right) {
            if(nums[a] <= nums[b]) {
                a++;
            } else {
                int temp = nums[b];
                for(int i = b; i >a; --i) {
                    nums[i] = nums[i-1];
                }
                nums[a] = temp;
                a ++;
                mid ++;
                b ++;
            }
        }
    }
    
    void mergesort(vector<int>& nums, int left, int right) {
        if(left == right) {
            return;
        }
        int mid = left + (right - left) /2;
        mergesort(nums,left, mid);
        mergesort(nums,mid + 1,right);
        merge(nums,left,mid,right);
    }
    
    int partition(vector<int>& nums,int low, int high) {
        int pindex = (rand()%(high - low + 1)) + low;
        swap(nums[low], nums[pindex]);
        int pivot = nums[low];
        while(low < high) {
            while(low < high && nums[high] >= pivot) high --;
            nums[low] = nums[high];
            while(low < high && nums[low] <= pivot) low ++;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }
    
    void quicksort(vector<int>& nums, int left, int right) {
        if(left < right) {
            int mid = partition(nums,left,right);
            quicksort(nums,left,mid-1);
            quicksort(nums,mid+1,right);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        
        // bubble sort
        //bubblesort(nums);
        
        // heap sort
        // int n = nums.size();
        //heapsort(nums,n);
        
        // merge sort
        //mergesort(nums, 0, nums.size() - 1);
        
        // quick sort
        quicksort(nums, 0, nums.size() - 1);
        
        return nums;
    }
};