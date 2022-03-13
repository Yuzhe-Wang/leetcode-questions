/*
Description:

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.
*/

/*
key ideas: 
1. starting from the middle, and expand to both sides to check palindromes
2. break into two cases: odd length palindromes, even length palindromes
*/

// solution:
#include<iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        int length = s.length();
        
        // count the odd length palindromes
        for(int i = 0; i < length; ++i) {
            int left = i;
            int right = i;
            while(s[left] == s[right]) {
                result ++;
                left --;
                right ++;
                if(left < 0 || right >= length) {
                    break;
                }
            }
        }
        
        //count the even length palindromes
        for(int j = 0; j < length; ++j) {
            int left = j;
            int right = j + 1;
            while(s[left] == s[right]) {
                result ++;
                left --;
                right ++;
                if(left < 0 || right >= length) {
                    break;
                }
            }
        }
        
        return result;
    }
};