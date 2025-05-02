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
    int length(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 1 && head->next == NULL)
            return NULL;
        int len = length(head);
        int x = len - n - 1;
        if(x < 0)
            return head->next;
        ListNode* temp = head;
        while(x-- && temp != NULL){
            temp = temp->next;
        }
        if(temp)
            temp->next = temp->next->next;
        return head;
    }
};