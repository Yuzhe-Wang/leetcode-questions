/*
Description:
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

// idea: dfs, inorder

#include <iostream>
#include <vector>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    
    void dfs(TreeNode* root, vector<int>& result) {
        if(root == nullptr) return;
        dfs(root -> left, result);
        result.push_back(root -> val);
        dfs(root -> right, result);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
};