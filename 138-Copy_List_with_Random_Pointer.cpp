/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 Node* next;
 Node* random;
 
 Node() {}
 
 Node(int _val, Node* _next, Node* _random) {
 val = _val;
 next = _next;
 random = _random;
 }
 };
 */
class Solution { // method one using hash map with space complexicity O(n)
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)    return NULL;
        
        unordered_map<Node*, Node*> map;
        Node* p1 = head; // p1 is to scan list
        Node* p2 = new Node (head->val, NULL, NULL);// p2 is to copy list
        map.emplace(head, p2);
        
        while(p1 != NULL){
            
            if(p1->next != NULL){
                if(map.find(p1->next) != map.end()){
                    p2->next = map[p1->next];
                }else{
                    p2->next = new Node (p1->next->val, NULL, NULL);
                    map.emplace(p1->next, p2->next);
                }
            }
            
            if(p1->random != NULL){
                if(map.find(p1->random) != map.end()){
                    p2->random = map[p1->random];
                }else{
                    p2->random = new Node(p1->random->val, NULL, NULL);
                    map.emplace(p1->random, p2->random);
                }
            }
            
            p1 = p1->next;
            p2 = p2->next;
        }
        return map[head];
    }
};

//method 2:
class Solution { // method to use extra space complexity O (1)
public:
    Node* copyRandomList(Node* head) {
        // one example: 1(2)->2(4)->3(1)->4(NULL)
        // step1: copy head: 1(2)->1'(NULL)->2(4)->2'(NULL)->3(1)->3'(NULL)->4(NULL)->4'(NULL)
        // step2: copy random: 1(2)->1'(2')->2(4)->2'(4')->3(1)->3'(1')->4(NULL)->4'(NULL)
        // step3: split these two list
        if(head==NULL)  return NULL;
        
        Node* curr = head;
        copy_head(curr);
        
        curr = head;
        copy_randome(curr);
        
        curr = head;
        Node* newhead = split_list(curr);
        return newhead;
    }
    
private:
    void copy_head(Node* head){
        while(head!=NULL){
            Node* new_node = new Node(0,NULL,NULL);
            new_node->val = head->val;
            new_node->next = head->next;
            head->next = new_node;
            head = new_node->next;
        }
    }
    
    void copy_randome(Node* head){
        while(head!=NULL){
            if(head->random!=NULL){
                head->next->random = head->random->next; // key point
            }
            head = head->next->next;
        }
    }
    
    Node* split_list(Node* head){
        Node* new_node = head->next;
        
        while(head!=NULL){
            Node* temp = head->next;
            head->next = temp->next;
            
            if(temp->next!=NULL){
                temp->next = temp->next->next;
            }
            head = head->next; // careful
        }
        return new_node;
    }
};





