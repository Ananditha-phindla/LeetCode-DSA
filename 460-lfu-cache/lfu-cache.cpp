class Node{
    public:
        int key;
        int val;
        int freq;
        Node* prev;
        Node *next;
        Node(int key,int val){
            this->key = key;
            this->val = val;
            freq = 1;
            prev = next = NULL;
        }
};

class LFUCache {
public:
    int size;
    unordered_map<int,Node*>mp;
    unordered_map<int,Node*>freq_mp;
    Node *dummy;
    Node *tail;
    LFUCache(int capacity) {
        size = capacity;
        dummy = new Node(-1,-1);
        tail = new Node(-1,-1);
        dummy->next = tail;
        tail->prev = dummy;
        dummy->freq = 0;
        tail->freq = 0;
        mp.clear();
        freq_mp.clear();
    }
    
    void deleteNode(Node* n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void addAfterNode(Node *p,Node* n){
        n->next = p->next;
        n->prev = p;
        p->next = n;
        n->next->prev = n;
    }

    void increaseFreq(Node *n){
        int curr_freq = n->freq;
        int prev_freq = n->prev->freq;
        if(n == freq_mp[curr_freq]){
            if(curr_freq == prev_freq)
                freq_mp[curr_freq] = n->prev;
            else
                freq_mp.erase(curr_freq);
        }
        if(freq_mp.count(curr_freq+1)){
            addAfterNode(freq_mp[curr_freq+1],n);
        }
        else if(freq_mp.count(curr_freq)){
            addAfterNode(freq_mp[curr_freq],n);
        }
        else
            addAfterNode(n->prev,n);
        freq_mp[curr_freq+1] = n;
        n->freq += 1;
    }

    int get(int key) {
        if(!mp.count(key))
            return -1;
        Node *n = mp[key];
        deleteNode(n);
        cout << "In get" << n->key << " ";
        cout << endl;
        increaseFreq(n);
        return n->val;
        
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node *n = mp[key];
            n->val = value;
            deleteNode(n);
            cout << "In put" << n->key << " ";
            cout << endl;
            increaseFreq(n);
            return;
        }
        else{
            if(size == mp.size()){
                mp.erase(dummy->next->key);
                Node *n = dummy->next;
                int curr_freq = n->freq;
                //int prev_freq = n->prev->freq;
                if(n == freq_mp[curr_freq]){
                    freq_mp.erase(curr_freq);
                }
                deleteNode(dummy->next);
            }
            Node *n = new Node(key,value);
            mp[key] = n;
            if(freq_mp.count(1)){
                addAfterNode(freq_mp[1],n);
            }
            else
                addAfterNode(dummy,n);
            freq_mp[1] = n;
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */