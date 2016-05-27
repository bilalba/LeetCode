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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        while(n-- > 0)
            cur = cur->next;
        ListNode* ref = head;
        if (!cur) 
            return ref->next;
        while (cur->next) {
            ref = ref->next;
            cur =  cur->next;
        }
        ref->next = ref->next->next;
        return head;
    }
};