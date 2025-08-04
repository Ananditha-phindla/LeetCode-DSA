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
    bool solve(TreeNode* root, int targetSum,int currSum){
        if(root && !root->left && !root->right && targetSum == currSum+root->val)
            return true;
        if(!root)
            return false;
        return solve(root->left,targetSum,currSum+root->val) || solve(root->right,targetSum,currSum+root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root && targetSum == 0)
            return false;
        if(!root)
            return false;
        return solve(root,targetSum,0);
        
    }
};