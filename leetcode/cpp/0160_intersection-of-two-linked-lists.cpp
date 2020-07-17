/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int listSize(ListNode *L) {
        int n = 0;
        while (L) {
            L = L->next;
            ++n;
        }
        return n;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = listSize(headA);
        int sizeB = listSize(headB);
        int i;
        
        if (sizeA > sizeB) {
            for (i = 0; i < (sizeA - sizeB); ++i)
                headA = headA->next;
        } else {
            for (i = 0; i < (sizeB - sizeA); ++i)
                headB = headB->next;
        }
        
        while (headA && headB) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return 0;
    }
};