
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* lastnode = dummy;
        
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                lastnode->next = l1;
                l1 = l1->next;
            }else{
                lastnode->next = l2;
                l2 = l2->next;
            }
            lastnode = lastnode->next;
        }
        
        if(l1 == NULL){
            lastnode->next = l2;
        }else{
            lastnode->next = l1;
        }
        
        return dummy->next;
    }
};
