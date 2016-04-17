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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        long sum = l1->val + l2->val;

        long multiplier = 1;

        while(l1->next || l2->next) {

            multiplier = multiplier *10;

            if (l1->next) {

                sum += l1->next->val* multiplier;

                l1 = l1->next;

            }

            if (l2->next) {

                sum += l2->next->val* multiplier;

                l2 = l2->next;

            }

            cout << sum << "\n";

        }

        ListNode* a = new ListNode(sum%10);

        ListNode* temp = a;

        while (sum/10 != 0) {

            sum = sum/10;

            ListNode* adder = new ListNode(sum%10);

            temp ->next = adder;

            temp = adder;

        }

        return a;

    }

};
