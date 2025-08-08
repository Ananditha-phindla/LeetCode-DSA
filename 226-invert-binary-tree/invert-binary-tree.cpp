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
    TreeNode* solve(TreeNode* root,TreeNode* l,TreeNode* r){
        if(!root)
            return NULL;
        root->left = r;
        root->right = l;
        if(root->left)
            root->left = solve(root->left,root->left->left,root->left->right);
        if(root->right)
            root->right = solve(root->right,root->right->left,root->right->right);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        return solve(root,root->left,root->right);
    }
};