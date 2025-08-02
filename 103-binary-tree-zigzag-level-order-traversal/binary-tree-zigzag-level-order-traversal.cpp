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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        deque<TreeNode*> dq;
        bool isOdd = true;
        dq.push_back(root);
        vector<vector<int>>ans;
        while(!dq.empty()){
            int s = dq.size();
            vector<int>temp;
            for(int i=0;i<s;i++){
                TreeNode* curr = dq.front();
                dq.pop_front();
                temp.push_back(curr->val);
                if(curr->left)
                    dq.push_back(curr->left);
                if(curr->right)
                    dq.push_back(curr->right);
            }
            if(isOdd)
                ans.push_back(temp);
            else{
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            isOdd = !(isOdd);
        }
        return ans;
    }
};