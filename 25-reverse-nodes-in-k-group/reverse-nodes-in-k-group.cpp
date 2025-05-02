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
    ListNode* findKthNode(ListNode* temp,int k){
        while(--k && temp != NULL){
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverse(ListNode* temp){
        if(!temp || !temp->next)
            return temp;
        ListNode* rh = reverse(temp->next);
        temp->next->next = temp;
        temp->next = NULL;
        return rh;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* kthNode = findKthNode(temp,k);
            if(!kthNode){
                prev->next = temp;
                break;
            }
            ListNode* nn = kthNode->next;
            kthNode->next = NULL;
            kthNode = reverse(temp);
            if(head == temp)
                head = kthNode;
            else
                prev->next = kthNode;
            prev = temp;
            temp = nn;
        }
        return head;
    }
};