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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    int size =1;
    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
        ListNode* node = head;
        while (node->next != NULL) 
            node = node->next, size++;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int num = rand()%size;
        ListNode* node = head;
        int counter= 0;
        while(counter != num) node = node->next, counter++;
        return node->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */