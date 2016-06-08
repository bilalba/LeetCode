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
        map<ListNode*, int> map;
        if (!head)
            return false;
        ListNode* temp = head;
        map[head] = 1;
        while (temp->next) {
            if (map.count(temp->next) != 0)
                return true;
            map[temp] = 1;
            temp = temp->next;
            
        }
        return false;
    }
};