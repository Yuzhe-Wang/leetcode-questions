/*
Description:
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
*/

/*
do what it does, 
3 approaches to find the max within a window
1. linear scan O(n-k+1)*k
2. heap/Bst (multiset in cpp) O(n-k+1)*logk
3. monotonic queue
*/


#include <iostream>
#include <set>
#include <deque>
#include <vector>

using namespace std;

class monotonicQueue {
    public:
    void push(int x) {
        while(!queue.empty() && x > queue.back()) {
            queue.pop_back();
        }
        queue.push_back(x);
    }
    
    void pop() {
        queue.pop_front();
    }
    
    int top() {
        return queue.front();
    }
    
    private:
    deque<int> queue;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // // solution 1, linear scan in the window. TLE
        // vector<int> result;
        // int left = 0; 
        // int right = k-1;
        // while(right < nums.size()) {
        //     int localMax = nums[left];
        //     for(int i = left; i <= right; ++i) {
        //         localMax = max(localMax, nums[i]);
        //     }
        //     result.push_back(localMax);
        //     left ++;
        //     right ++;
        // }
        // return result;
        
        // solution 2: heap/bst
        // multiset: can pass in greater<int> or less<int>
        // greatest at the begin() as a max heap does
        // insert and erase, erase can take a value but will erase all the occurance of that value in the multiset
//         vector<int> result;
//         int left = 0;
//         int right = k - 1;
        
//         multiset<int, greater<int>> bst;
//         for(int i = 0; i < k - 1; ++i) {
//             bst.insert(nums[i]);
//         }
        
//         while(right < nums.size()) {
//             bst.insert(nums[right]);
//             int localMax = *(bst.begin());
//             result.push_back(localMax);
//             bst.erase(bst.find(nums[left]));
//             left ++;
//             right ++;
//         }
//         return result;
        
        // solution 3: monotonic queue
        vector<int> result;
        monotonicQueue queue;
        int left = 0;
        int right = k - 1;
        for(int i = left; i < right; ++i) {
            queue.push(nums[i]);
        }
        int localMax;
        while(right < nums.size()) {
            queue.push(nums[right]);
            localMax = queue.top();
            result.push_back(localMax);
            //remove nums[left]
            if(nums[left] == localMax) {
                queue.pop();
            }
            left ++;
            right ++;
        }
        return result;
    }
};