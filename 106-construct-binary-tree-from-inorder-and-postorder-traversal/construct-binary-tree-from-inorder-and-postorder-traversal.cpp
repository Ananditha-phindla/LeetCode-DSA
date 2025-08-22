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
    TreeNode* solve(vector<int>& post, unordered_map<int,int>& mp, int lo, int hi, int &idx){
        if(lo > hi)
            return NULL;
        TreeNode* root = new TreeNode(post[idx]);
        idx--;
        root->right = solve(post,mp,mp[root->val]+1,hi,idx);
        root->left = solve(post,mp,lo,mp[root->val]-1,idx);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        int idx = n-1;
        return solve(postorder,mp,0,n-1,idx);
    }
};