#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <future>
#include <functional>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <queue>

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
            for(const auto& c: i) {
                letters.insert(c);
            }
        }
        
        // parse the input and create a graph(adjacency list)
        for(int i = 0; i < words.size(); ++i) {
            for(int j = i + 1; j < words.size(); ++j) {
                const string& a = words[i];
                const string& b = words[j];
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
                if(a.length() > b.length() && k == length) {
                    return "";
                }
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
        if(states[curr] == 1) return true; // cycle detected
        if(states[curr] == 2) return false;
        
        states[curr] = 1;
        for(const auto& i: adj[curr]) {
            if(dfs(i, adj, ans, states)) return true;
        }
        ans += curr;
        states[curr] = 2;
        return false;
    }
};

int main() {
    vector<string> input = {"dvpzu","bq","lwp","akiljwjdu","vnkauhh","ogjgdsfk","tnkmxnj","uvwa","zfe","dvgghw","yeyruhev","xymbbvo","m","n"};
    Solution s;
    string ans = s.alienOrder(input);
    cout<<ans<<endl;
}
