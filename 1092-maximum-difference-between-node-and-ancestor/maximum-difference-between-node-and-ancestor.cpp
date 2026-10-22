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
    vector<int> solve(TreeNode* root, int& ans){
        if(!root->left && !root->right)
            return {root->val,root->val};
        vector<int> lft(2,-1);
        vector<int> rgt(2,-1);
        if(root->left){
            lft = solve(root->left,ans);
        }
        if(root->right){
            rgt = solve(root->right,ans);
        }
        int mini = min({lft[0] == -1 ? INT_MAX : lft[0],lft[1] == -1 ? INT_MAX : lft[1],rgt[0] == -1 ? INT_MAX : rgt[0],rgt[1] == -1 ? INT_MAX : rgt[1]});
        int maxi = max({lft[0] == -1 ? INT_MIN : lft[0],lft[1] == -1 ? INT_MIN : lft[1],rgt[0] == -1 ? INT_MIN : rgt[0],rgt[1] == -1 ? INT_MIN : rgt[0]});
        ans = max({abs(root->val-maxi),abs(root->val-mini),ans});
        return {max({mini,maxi,root->val}),min({mini,maxi,root->val})};
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};