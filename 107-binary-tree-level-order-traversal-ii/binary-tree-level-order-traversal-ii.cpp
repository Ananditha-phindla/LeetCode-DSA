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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL)
            return {};
        deque<TreeNode*> dq;
        dq.push_back(root);
        vector<vector<int>> ans;
        while(!dq.empty()){
            int s = dq.size();
            vector<int> temp;
            for(int i=0;i<s;i++){
                TreeNode* n = dq.front();
                dq.pop_front();
                if(n->left)
                    dq.push_back(n->left);
                if(n->right)
                    dq.push_back(n->right);
                temp.push_back(n->val);
            }
            ans.insert(ans.begin(),temp);
        }
        return ans;
    }
};