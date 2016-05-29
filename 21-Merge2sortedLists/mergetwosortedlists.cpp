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
        ListNode* head;
        
        if (!l1) {
            if (!l2) {
                return NULL;
            } else {
                return l2;
            }
        } else if (!l2) {
            return l1;
        }
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        ListNode* temp = head;
        while((l1) || (l2)) {
            if (l1) {
                if (l2) {
                    if (l1->val < l2->val) {
                        temp->next = l1;
                        l1 = l1->next;
                    } else {
                        temp->next = l2;
                        l2 = l2->next;
                    }
                temp = temp->next;
                } else {
                    temp->next = l1;
                    break;
                }
            } else if (l2) {
                temp->next = l2;
                break;
            }
        
        }
        return head;
    }
};