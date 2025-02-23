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
    TreeNode* construct(vector<int>& preorder,int &idx,unordered_map<int,int>&mp,int high){
        if(idx >= preorder.size())
            return NULL;
        int val = preorder[idx];
        if(mp[val] > high)
            return NULL;
        TreeNode* nn = new TreeNode(val);
        idx++;
        nn->left = construct(preorder,idx,mp,mp[val]-1);
        nn->right = construct(preorder,idx,mp,mp[val]-1);
        return nn;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int p = postorder.size();
        for(int i=0;i<p;i++)
            mp[postorder[i]] = i;
        int idx = 0;
        return construct(preorder,idx,mp,p-1);
    }
};