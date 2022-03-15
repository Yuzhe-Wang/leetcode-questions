/*
Description:
A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
*/

// idea: dfs/recurrsion + backtracking
// a similar question was asked during bytedance 2022 tiktok backend intern interveiw

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    // helper for checking if the substring is valid
    bool valid(string temp) {
        if(temp.length() > 3) return false; // sometimes the substring will be greater than INT_MAX
        if(stoi(temp) < 0 || stoi(temp) > 255) return false; // should be within the range
        if(temp[0] == '0' && temp.length() > 1) return false; // should not have any leading 0's
        return true;
    }
    
    void helper(vector<string>& result, string s, int k, vector<string> ip) {
        // base case: no more dots available
        if(k == 0) {
            if(s.empty()) return;
            if(valid(s)) {
                string oneLine = "";
                for(int i= 0; i < ip.size(); ++i) {
                    oneLine += ip[i] + ".";
                }
                oneLine += s;
                result.push_back(oneLine);
            }
            return;
        }
        // recurrsion: try all possible positions for the current dot
        for(int i = 1; i <= s.length(); ++i) {
            string temp = s.substr(0,i);
            if(valid(temp)) {
                ip.push_back(temp); // make a choice
                string next = s.substr(i);
                helper(result, next, k-1, ip); // explore the decision space
                ip.pop_back(); // undo the choice
            } else {
                break;
            }
        }
    }

    // the driver function
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> ip;
        helper(result, s, 3, ip);
        return result;
    } 
};
