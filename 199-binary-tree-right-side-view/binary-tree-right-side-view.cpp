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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        vector<int> ans;
        deque<TreeNode*> dq;
        dq.push_back(root);
        TreeNode* lastNode = dq.back(); 
        while(!dq.empty()){
            TreeNode* curr = dq.front();
            dq.pop_front();
            if(curr->left)
                dq.push_back(curr->left);
            if(curr->right)
                dq.push_back(curr->right);
            if(lastNode == curr){
                ans.push_back(curr->val);
                lastNode = dq.back();
            }
        }
        return ans;
    }
};