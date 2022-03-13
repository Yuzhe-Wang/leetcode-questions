/*
Description:
You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.
*/

// basic idea: we can split whenever prev_max <= next_min, construct two arrays
// to store the max value prior to i and the min value after i for all i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int size = arr.size();
        
        // the prev_max array should be filled from the front to the end
        vector<int> prev_max(size);
        int maxVal = arr[0];
        for(int i = 0; i < size; ++i) {
            maxVal = max(maxVal, arr[i]);
            prev_max[i] = maxVal;
        }
        
        // the next_min array should be filled in a backward direction
        vector<int> next_min(size);
        int minVal = arr[size - 1];
        for(int j = size - 1; j >=0; --j) {
            minVal = min(minVal, arr[j]);
            next_min[j] = minVal;
        }
        
        // whenever prev_max[i] < next_min[i+1], we can split
        int count = 0;
        for(int k = 0; k < size - 1; ++k) {
            if(prev_max[k] <= next_min[k+1]) {
                count++;
            }
        }
        
        // count is the max number of splits, plus one to get the max number of chunks
        return count + 1;
    }
};
