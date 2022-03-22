/*
Description:
There is a new alien language that uses the English alphabet. However, the order among the letters is unknown to you.

You are given a list of strings words from the alien language's dictionary, where the strings in words are sorted lexicographically by the rules of this new language.

Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there is no solution, return "". If there are multiple solutions, return any of them.

A string s is lexicographically smaller than a string t if at the first letter where they differ, the letter in s comes before the letter in t in the alien language. If the first min(s.length, t.length) letters are the same, then s is smaller if and only if s.length < t.length.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        string ans = "";
        unordered_map<char, int> states;
        
        // store all letters
        unordered_set<char> letters;
        for(const auto& i: words) {
            for(const auto c: i) {
                letters.insert(c);
            }
        }
        
        // parse the input and create a graph(adjacency list)
        for(int i = 0; i < words.size(); ++i) {
            for(int j = i; j < words.size(); ++j) {
                const string a = words[i];
                const string b = words[j];
                int length = min(a.length(), b.length());
                int k = 0;
                for(k = 0; k < length; ++k) {
                    if(a[k] != b[k]) {
                        if(find(adj[a[k]].begin(), adj[a[k]].end(), b[k]) == adj[a[k]].end()) {
                            adj[a[k]].push_back(b[k]);
                            letters.erase(a[k]);
                            letters.erase(b[k]);
                        }
                        break;
                    }
                }
                if(a.length() > b.length() && k == length) return "";
            }
        }
        
        // construct a state map, state: 0 = unvisited, 1 = visiting, 2= visited/removed
        for(const auto& x: adj) {
            states[x.first] = 0;
        }
        
        //topological sort using dfs
        for(const auto& i: adj) {
            if(dfs(i.first, adj, ans, states)) {
                return "";
            }
        }
        reverse(ans.begin(), ans.end());
        if(!letters.empty()) {
            for(const auto& i: letters) {
                ans += i;
            }
        }
        return ans;
    }
private:
    bool dfs(char curr, unordered_map<char, vector<char>>& adj, string& ans,unordered_map<char, int>& states) { // return true if cycle detected
        if(states[curr] == 1) {
            return true; // cycle detected
        }
        if(states[curr] == 2) {
            return false;
        }
        
        states[curr] = 1;
        if(adj.find(curr) != adj.end()) { //一定要检查，要不unordered_map会default construct,在线过不了
            for(const auto& i: adj[curr]) {
                if(dfs(i, adj, ans, states)) {
                    return true;
                }
            }
        }
        states[curr] = 2;
        ans += curr;
        return false;
    }
};