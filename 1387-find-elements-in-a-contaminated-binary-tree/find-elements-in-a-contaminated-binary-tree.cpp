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
class FindElements {
public:
    unordered_set<int>myset;
    void DFS(TreeNode* root,int p){
        if(root == NULL)
            return;
        if(root->left){
            myset.insert(2*p+1);
            DFS(root->left,2*p+1);
        }
        if(root->right){
            myset.insert(2*p+2);
            DFS(root->right,2*p+2);
        }
    }
    FindElements(TreeNode* root) {
        myset.clear();
        myset.insert(0);
        root->val = 0;
        DFS(root,0);
    }
    
    bool find(int target) {
        if(myset.count(target))
            return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */