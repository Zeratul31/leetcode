
class LRUCache {
public: // method of double link list
    struct Node // hard part
    {
        int val;
        int key;
        Node * prev;
        Node * next;
        Node(int k, int v): key(k), val(v), prev(NULL), next(NULL){};
    };
    
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail; // put most recent at tail
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        
        Node* temp = mp[key];
        
        temp->prev->next = temp->next; // kick out temp node and move to tail
        temp->next->prev = temp->prev;
        
        move_to_tail(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            mp[key]->val = value;
            get(key); // move to tail and kick out this node
        }
        else
        {
            if(mp.size() == cap) // remove least recent node head
            {
                mp.erase(head->next->key); // need to erase
                head->next = head->next->next;
                head->next->prev = head;
            }
            
            Node* temp = new Node(key, value);
            mp.emplace(key, temp);
            move_to_tail(temp);
        }
    }
    
    void move_to_tail(Node* curr)
    {
        curr->prev = tail->prev;
        tail->prev = curr;
        curr->prev->next = curr;
        curr->next = tail;
        
        // below also work
        // curr->prev = tail->prev;
        // curr->next = tail;
        // tail->prev->next = curr;
        // tail->prev = curr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
