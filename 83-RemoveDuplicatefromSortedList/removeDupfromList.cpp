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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp =head;
        if (!head)
            return head;
        while (temp->next) {
            while (temp->val == temp->next->val) {
                temp->next = temp->next->next;
                if (!(temp->next))
                    break;
            }
            temp = temp->next;
            if (!temp)
                break;
        }
        return head;
        
    }
};