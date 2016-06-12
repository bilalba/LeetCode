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

    bool simpleswap(ListNode** a, ListNode** b) {
        
        ListNode* one = (*a);
        ListNode* two = (*b);
        if (!one)
            return false;
        if (!two)
            return false;    
        one->next = two->next;
        two->next = one;
        (*a) = two;
        // *b = one;
        return true;
    }
    bool swap(ListNode** a, ListNode** b) {
         if (!(*a))
         return false;
        if (!(*b))
            return false;
        ListNode *temp;
        temp = *b;
        *b = *a;
        *a = temp;
        temp = (*a)->next;
        (*a)->next = (*b)->next;
        (*b)->next = temp;
        return true;
    }
    
    ListNode** getNth(ListNode** iter, int n) {
        int i;
        for (i = 0; i < n; i++) {
            if (!((*iter)->next))
                break;// end.
            iter = &((*iter)->next); // will this give me the pointer to next, or will it give me pointer to 
        }
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
            xth = k;
            if (!*ppStart)
                return *pStart;
            iter = getNth(ppStart, xth-1);
            if (iter){
                if (xth !=2){
                if (!swap(ppStart, iter))
                    return *pStart;
                    
                } else {
                    if (!simpleswap(ppStart, iter))
                        return *pStart;
                    iter = ppStart;
                    
                }
            }else{ // we done.
                return *pStart;
            }
             ListNode* last = *iter;
           
            if (xth ==2)
            last = ((*iter)->next);
            
            while (xth-2 > 1) {
                xth= xth-2;
                ppStart = &((*ppStart)->next);
                iter = getNth(ppStart, xth-1);
                if (iter){
                    if (!swap(ppStart, iter))
                        return *pStart;
                    }else // we done.
                        return *pStart;
            }
            
            if (last)
                ppStart = &(last->next);
            else 
                return *pStart;
        }
    }
};