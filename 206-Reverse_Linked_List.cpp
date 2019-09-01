/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {// recursively method
    //     首先我们先考虑 reverseList 函数能做什么，它可以翻转一个链表，并返回新链表的头节点，也就是原链表的尾节点。 所以我们可以先递归处理 reverseList(head->next)，这样我们可以将以head->next为头节点的链表翻转，并得到原链表的尾节点tail，此时head->next是新链表的尾节点，我们令它的next指针指向head，并将head->next指向空即可将整个链表翻转，且新链表的头节点是tail。
    // 空间复杂度分析：总共递归 nn 层，系统栈的空间复杂度是 O(n)O(n)，所以总共需要额外 O(n)O(n) 的空间。
    // 时间复杂度分析：链表中每个节点只被遍历一次，所以时间复杂度是 O(n)O(n)。
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* new_node = reverseList(head -> next);
        head->next ->next = head;
        head->next = NULL;
        return new_node;        
    }
};

/*
 class Solution { // iteratively method
 // 翻转即将所有节点的next指针指向前驱节点。
 // 由于是单链表，我们在迭代时不能直接找到前驱节点，所以我们需要一个额外的指针保存前驱节点。同时在改变当前节点的next指针前，不要忘记保存它的后继节点。
 
 // 空间复杂度分析：遍历时只有3个额外变量，所以额外的空间复杂度是 O(1)O(1)。
 // 时间复杂度分析：只遍历一次链表，时间复杂度是 O(n)O(n)。
 
 public:
 ListNode* reverseList(ListNode* head) {
 // NULL->1->2->3
 // NULL->3->2->1
 ListNode* pre = NULL;
 ListNode* curr = head;
 
 while(curr != NULL){
 ListNode* temp = curr->next;
 curr->next = pre;            
 pre = curr;
 curr = temp;
 }
 
 return pre;
 }
 };
 */
