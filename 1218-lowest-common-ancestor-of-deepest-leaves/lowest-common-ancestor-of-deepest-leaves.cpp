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
    void check(TreeNode* root,unordered_set<TreeNode*>&leaves,int &cnt){
        if(root == NULL)
            return;
        if(leaves.count(root))
            cnt++;
        if(root->left)
            check(root->left,leaves,cnt);
        if(root->right)
            check(root->right,leaves,cnt);
    }
    TreeNode* solve(TreeNode* root,unordered_set<TreeNode*>&leaves){
        int cnt = 0;
        check(root->left,leaves,cnt);
        if(cnt == leaves.size())
            return solve(root->left,leaves);
        else if(cnt == 0)
            return solve(root->right,leaves);
        return root;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        unordered_set<TreeNode*>leaves;
        while(!q.empty()){
            int s = q.size();
            leaves.clear();
            for(int i=0;i<s;i++){
                TreeNode* curr = q.front();
                q.pop();
                leaves.insert(curr);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        if(leaves.size() == 1)
            return *(leaves.begin());
        return solve(root,leaves);
    }
};