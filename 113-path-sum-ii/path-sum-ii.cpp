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
    void solve(TreeNode* root, int targetSum,int currSum,vector<vector<int>>&ans,vector<int>temp){
        if(root && !root->left && !root->right && currSum+root->val == targetSum){
            temp.push_back(root->val);
            ans.push_back(temp);
            return;
        }
        if(!root)
            return;
        temp.push_back(root->val);
        solve(root->left,targetSum,currSum+root->val,ans,temp);
        solve(root->right,targetSum,currSum+root->val,ans,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(root,targetSum,0,ans,temp);
        return ans;
    }
};