
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        
        // hard part: left is first and right is late
        auto cmp = [] (ListNode* left, ListNode* right){
            return left->val > right->val; // if this is true, right is in top
        };
        priority_queue< ListNode*, vector<ListNode*>, decltype(cmp) > queue(cmp);// hard
        
        for(auto head: lists){
            if(head!=NULL) // handle null case
                queue.push(head);
        }
        
        while(!queue.empty()){
            ListNode* temp = queue.top();
            queue.pop();
            if(temp->next!=NULL)
                queue.push(temp->next);
            
            cur->next = temp;
            cur = cur->next;
        }
        return dummy->next;
    }
};
