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
    int solve(TreeNode* root,int &ans) {
        if(root == NULL)
            return INT_MIN;
        int left = max(solve(root->left,ans),0);
        int right = max(solve(root->right,ans),0);
        int curr = left+ right + root->val;
        ans = max(ans,curr);
        curr = max(left,right)+root->val;
        return curr;
    }

    int maxPathSum(TreeNode* root) {
        if(!root->left && !root->right)
            return root->val;
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};