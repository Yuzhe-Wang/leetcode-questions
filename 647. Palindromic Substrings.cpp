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

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        int length = s.length();
        //counting the number of odd length palindroms
        for(int i = 0; i < length; i++) {
            int l = i;
            int r = i;
            while(l >=0 && r < length) {
                if(s[l] == s[r]) {
                    result ++;
                    l --;
                    r ++;
                } else {
                    break;
                }
            }
        }
        //counting the number of even length palindroms
        for(int j = 0; j < length; j++) {
            int l = j; 
            int r = j + 1;
            while(l >=0 && r < length) {
                if(s[l] == s[r]) {
                    result ++;
                    l --;
                    r ++;
                } else {
                    break;
                }
            }
        }
        return result;
    }
};