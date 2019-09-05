
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution { //method 1 to check whole length and
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)  return NULL;
        
        int lengthA = get_length(headA);
        int lengthB = get_length(headB);
        
        ListNode * pA = headA;
        ListNode * pB = headB;
        
        if(lengthA<lengthB){
            for(int i=0; i< (lengthB-lengthA); i++){
                pB = pB->next;
            }
        }
        else{
            for(int i=0; i< (lengthA-lengthB); i++){
                pA = pA->next;
            }
        }
        
        while(pA!=NULL && pB!=NULL){
            if(pA == pB)
                return pA;
            
            pA = pA->next;
            pB = pB->next;
        }
        return NULL;
    }
    
    int get_length(ListNode *head){
        int length = 0;
        while(head != NULL){
            head = head->next;
            length++;
        }
        return length;
    }
};

// method2

class Solution { // method 2: a path + b path + c path is same!
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)  return NULL;
        
        ListNode * pA = headA;
        ListNode * pB = headB;
        
        while(pA!=pB){
            
            pA = pA->next;
            pB = pB->next;
            
            if(pA == pB)    return pA; // very important for non-intersect case
            
            if(pA == NULL)
                pA = headB;
            
            if(pB == NULL)
                pB = headA;
        }
        return pA;
    }
};
