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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return false;
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while(slow!=fast){
            if(fast==NULL || fast->next==NULL)
                return false;
            
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};

//OR:

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return false;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast!=NULL && fast->next !=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};
