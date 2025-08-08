/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root, int k,unordered_set<int>&myset){
        if(!root)
            return false;
        if(myset.count(k-root->val))
            return true;
        myset.insert(root->val);
        return solve(root->left,k,myset) || solve(root->right,k,myset);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>myset;
        return solve(root,k,myset);
        
    }
};