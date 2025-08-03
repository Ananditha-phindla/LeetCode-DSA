/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* findMid(ListNode* head){
        if(!head)
            return NULL;
        ListNode* sp = head;
        ListNode* fp = head;
        ListNode* sp_prev = NULL;
        while(fp && fp->next){
            sp_prev = sp;
            sp = sp->next;
            fp = fp->next->next;
        }
        return sp_prev;
    }

    TreeNode* solve(ListNode* head){
        if(!head)
            return NULL;
        if(!head->next){
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        ListNode* mid = findMid(head);
        TreeNode* root = new TreeNode(mid->next->val);
        root->right = solve(mid->next->next);
        mid->next = NULL;
        root->left = solve(head);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head);
        
        
    }
};