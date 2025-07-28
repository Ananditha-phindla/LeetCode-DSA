class Node{
    public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int key,int val){
        this->key = key;
        this->val = val;
        this->prev = this->next = NULL;
    }
};


class LRUCache {
public:
    int size;
    unordered_map<int,Node*>mp;
    Node *dummy;
    Node *tail;
    LRUCache(int capacity) {
        size = capacity;
        dummy = new Node(-1,-1);
        tail = new Node(-1,-1);
        dummy->next = tail;
        tail->prev = dummy;
        mp.clear();
    }
    
    int get(int key) {
        if(!mp.count(key)){
            return -1;
        }
        Node *n = mp[key];
        deleteNode(n);
        addAtTail(n);
        return n->val;
        
    }
    
    void addAtTail(Node* n){
        n->prev = tail->prev;
        n->next = tail;
        tail->prev->next = n;
        tail->prev = n;
    }

    void deleteNode(Node *n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void put(int key, int value) {
        if(mp.count(key)){
            Node* n = mp[key];
            deleteNode(n);
            addAtTail(n);
            n->key = key;
            n->val = value;
            return;
        }
        if(size == mp.size()){
            mp.erase(dummy->next->key);
            deleteNode(dummy->next);
        }
        Node *n = new Node(key,value);
        addAtTail(n);
        mp[key] = n;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */