/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return head;
        vector<Node*>v;
        Node* temp = head;
        while(temp->next || temp->child){
            if(temp->child){
                if(temp->next){
                    v.push_back(temp->next);
                }
                temp->child->prev = temp;
                temp->next = temp->child;
                Node* n = temp;
                temp = n->child;
                n->child = NULL;
            }
            else
                temp = temp->next;
        }
        while(!v.empty()){
            temp->next = v.back();
            temp->next->prev = temp;
            while(temp->next != NULL)
                temp = temp->next;
            v.pop_back();
        }
        return head;
    }
};