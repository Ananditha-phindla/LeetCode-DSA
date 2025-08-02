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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, unordered_map<int,int>& inorderMp, int lo, int hi,int &idx){
        if(lo > hi)
            return NULL;
        TreeNode* nn = new TreeNode(postorder[idx]);
        int l = inorderMp[postorder[idx]];
        idx--;
        nn->right = solve(inorder,postorder,inorderMp,l+1,hi,idx);
        nn->left = solve(inorder,postorder,inorderMp,lo,l-1,idx);
        return nn;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inorderMp;
        int n = inorder.size();
        int idx = n-1;
        for(int i=0;i<n;i++)
            inorderMp[inorder[i]] = i;
        return solve(inorder,postorder,inorderMp,0,n-1,idx);
    }
};