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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++){
            ListNode* head = lists[i];
            while(head != NULL){
                pq.push({head->val,head});
                head = head->next;
            }
        }
        if(pq.empty()){
            return NULL;
        }
        ListNode* head = pq.top().second;
        ListNode* temp = head;
        pq.pop();
        while(!pq.empty()){
            temp->next = pq.top().second;
            temp = temp->next;
            pq.pop();
        }
        return head;

    }
};