/*
Description:
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

/*
anagram: 1. t contains all the chars of s
2. each char appears exactly once
3. no additional chars

hashmap<letter, frequency>
s -> construct the map
t -> check
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() > t.length()) return false;
        unordered_map<char, int> map;
        // go through s to construct the map
        for(char i: s) {
            if(map.find(i) == map.end()) {
                map[i] = 1;
            } else {
                map[i] ++;
            }
        }
        
        // go through t to check true or false
        bool result = true;
        for(char j: t) {
            if(map.find(j) == map.end()) {
                result = false;
            } else if(map[j] == 0) {
                result = false;
            } else{
                map[j]--;
            }
        }
        return result;
    }
};