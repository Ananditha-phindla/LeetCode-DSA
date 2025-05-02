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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* f = head;
       // ListNode* s = head;
        while(f != NULL){
            if(f->next && f->val == f->next->val){
                f->next = f->next->next;
            }
            else
                f = f->next;
        }
        return head;
    }
};