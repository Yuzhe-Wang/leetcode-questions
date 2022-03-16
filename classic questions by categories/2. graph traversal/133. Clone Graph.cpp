/*
Description:
Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
*/

// idea: do dfs or bfs, use a hashmap to keep track of the already constructed nodes

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    
    Node* dfs(Node* node, unordered_map<Node*, Node*>& map) {
        Node* copy = new Node(node -> val);
        map[node] = copy;
        for(Node* i: (node -> neighbors)) {
            if(map.find(i) != map.end()) {
                (copy -> neighbors).push_back(map[i]);
            } else {
                (copy -> neighbors).push_back(dfs(i,map));
            }
        }
        return copy;
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> map;
        if(node == nullptr) {
            return node;
        } else {
            return dfs(node, map);
        }
    }
};


/* deep copy a graph -> traverse the graph and construct nodes accordingly
methods for traversal: DFS, BFS
note that the input is an adjacency list
have a hashmap for checking if the node is already constructed
DFS:
1 -> 2,4
2 -> 1,3
3 -> 2,4
4 -> 1,3
order of construction: 1, 2, 
*/