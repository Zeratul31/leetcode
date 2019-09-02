/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0); // use struct instead of point so u do not need to new and delete later
        dummy.next = head;
        ListNode* pre = &dummy;
        
        while(pre != NULL){
            pre = reverse_Knode(pre, k);
        }
        
        return dummy.next;      
    }
    
private:
    ListNode* reverse_Knode(ListNode* pre, int k){ // return 
        // pre->n1->n2->n3->...nk->nk+1
        // pre->nk->nk-1->...n1->nk+1
        
        if(k<=0)    return NULL;
        // if(pre=NULL)    return NULL;
        
        ListNode* node1 = pre->next;
        ListNode* nodek = pre;
        
        for(int i=0; i<k; i++){
            if(nodek==NULL)
                return NULL; // this means there are less than K node left and cannot finish k node reverse
            nodek = nodek->next;
        }
        
        if(nodek == NULL)   return NULL;
        
        ListNode* nodek_plus = nodek->next;
        
        reverse_linked_list(pre, node1, k);
        
        node1->next = nodek_plus;
        pre->next = nodek;
        
        return node1; // carefull !
    }
    
    void reverse_linked_list(ListNode* pre, ListNode* curr, int k){
        for(int i=0; i<k; i++){
            ListNode* temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }        
    }
};
