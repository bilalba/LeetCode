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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA; ListNode *temp2 = headB;
        int count1 = 0; int count2 = 0;
        if (!headA || !headB)
            return NULL;
        while (temp1->next) {
            count1++;
            temp1 = temp1->next;
        }
        while (temp2->next) {
            count2++;
            temp2 = temp2->next;
        }
        if (temp1 != temp2)
            return NULL;
        int diff;
        ListNode *big;
        ListNode *small;
        if (count1> count2) {
            diff = count1-count2;
            big = headA; small = headB;
        } else {
            diff = count2-count1;
            big = headB; small = headA;
        }
        for (int i = 0; i < diff; i++)
            big = big->next;
        while (big != small) {
            big= big->next;
            small= small->next;
        }
        return big;
        
    }
};