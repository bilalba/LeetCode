/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {// one optimization is to break loop when we find same as last element.
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int min= INT_MAX;
        int k=-1;
        ListNode* head = NULL;
        ListNode* iter;
        while (lists.size() != 0) {
            min= INT_MAX;
            k = -1;
            int size = lists.size();
            for (int i = 0; i < size; i++) {
                if (!lists[i]) {
                    lists.erase(lists.begin()+i);
                    size--;
                    i--;
                } else {
                    if (lists[i]->val < min) {
                        min = lists[i]->val;
                        k = i;
                    }
                }
            }
            if (k ==-1)
                return head;
            if (!head){
                head = lists[k];
                iter = head;
            } else {
                iter->next = lists[k];
                iter = iter->next;
            }
            lists[k] = lists[k]->next;
        }
        return head;
    }
};