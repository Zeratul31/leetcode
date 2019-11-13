
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        int capacity = hashTable.size() * 2;
        vector<ListNode*> NewhashTable (capacity, NULL); // carefull!
        
        for(int i = 0; i < hashTable.size(); i++)
        {
            ListNode* currentNode = hashTable[i];
            while(currentNode != NULL)
            {
                add(NewhashTable, currentNode->val, capacity);
                currentNode = currentNode->next;
            }
        }
        return NewhashTable;
    }
    
private:
    void add(vector<ListNode*> &NewhashTable, int val, int capacity)
    {
        int idx = hash(val, capacity);
        if(NewhashTable[idx] == NULL)
        {
            // ListNode* temp = new ListNode(val); // carefull !!
            NewhashTable[idx] = new ListNode(val);
        }
        else
        {
            ListNode* node = NewhashTable[idx]; // carefull!
            while(true)
            {
                if(node -> next == NULL)
                {
                    node -> next = new ListNode(val);
                    break;
                }
                else
                {
                    node = node -> next;
                }
            }
        }
    }
    
    int hash (int val, int capacity) // carefull!
    {
        return ( (val % capacity + capacity) % capacity );
    }
};
