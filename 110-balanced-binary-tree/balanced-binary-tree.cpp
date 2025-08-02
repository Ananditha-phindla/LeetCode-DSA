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
    int findHeight(TreeNode* root){
        if(root == NULL)
            return 0;
        return max(findHeight(root->left),findHeight(root->right))+1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int l_height = findHeight(root->left);
        int r_height = findHeight(root->right);
        int bf = l_height - r_height;
        cout << root->val << " " << l_height << " " << r_height << " " << bf << endl;
        cout << (bf < -1 || bf > 1) << endl;
        if(bf < -1 || bf > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
            
    }
};