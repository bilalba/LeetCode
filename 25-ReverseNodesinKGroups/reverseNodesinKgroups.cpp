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

    bool swap(ListNode** a, ListNode** b) {
         if (!(*a))
         return false;
        if (!(*b))
            return false;
        ListNode *temp;
        temp = *b;
        *b = *a;
        *a = temp;
        cout << *a;
       
        cout << "s3";
        temp = (*a)->next;
        (*a)->next = (*b)->next;
        (*b)->next = temp;
        cout << "s1";
        return true;
    }
    
    ListNode** getNth(ListNode** iter, int n) {
        int i;
        cout << "fs";
        for (i = 0; i < n; i++) {
            if (!((*iter)->next))
                break;// end.
            iter = &((*iter)->next); // will this give me the pointer to next, or will it give me pointer to 
        }
        cout << "fs";
        if (i < n)
            return NULL;
        return iter;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k ==1)
            return head;
        
        ListNode** pStart = &head;
        ListNode** ppStart = &head;
        ListNode** iter;
        
        
        int xth = k;
        while (true) {
            
            if (!*ppStart)
                return *pStart;
            iter = getNth(ppStart, xth-1);
            cout << "ll";
            if (iter){
                if (!swap(ppStart, iter))
                    return *pStart;
                    cout << "s4";
            }else{ // we done.
            cout << "g";
                return *pStart;
            }
            ListNode** last = iter;
            while (xth-2 > 1) {
                xth= xth-2;
                ppStart = &((*ppStart)->next);
                iter = getNth(ppStart, xth-1);
                if (iter)
                    if (!swap(ppStart, iter))
                        return *pStart;
                    else // we done.
                        return *pStart;
            }
            
            cout << "enddd";
            // if (!(*last))
            //     return *pStart;
            
            if ((*last))
                ppStart = &((*last)->next);
            else 
                return *pStart;
            cout << "shh";
            // cout << (*last)->next->val;
        }
    }
};