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
        if (!head)
            return false;
        ListNode* slow = head->next;
        ListNode* fast = head->next;
        if (!fast)
            return false;
        fast = fast->next;
        
        while (fast != slow) {
            if (slow->next)
                slow = slow->next;
            else return false;
            if (fast->next) {
                if (fast->next->next) {
                    fast = fast->next->next;
                } else return false;
            } else return false;
        }
        return true;
    }
};