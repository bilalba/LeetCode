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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        if (!head)
            return NULL;
        ListNode* last = NULL;
        if (temp->next) {
            head = temp->next;
            last = temp;
            ListNode* third = temp->next->next;
            temp->next->next= temp;
            temp->next = third;
            temp = temp->next;
        }
        if (!temp)
        return head;
        while (temp->next) {
            last->next = temp->next;
            ListNode* third = temp->next->next;
            temp->next->next = temp;
            temp->next = third;
            last = temp;
            temp = temp->next;
            if (!temp)
                return head;
        }
        return head;
    }
};