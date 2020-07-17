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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *S = 0, *p;
        if (l1 != 0 && l2 != 0) {
            int carry = 0;
            while (l1 != 0 && l2 != 0) {
                int x = l1->val + l2->val + carry;
                carry = x / 10;
                if (S == 0) {
                    S = p = new ListNode(x % 10);
                } else {
                    p->next = new ListNode(x % 10);
                    p = p->next;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            while (l1 != 0) {
                int x = l1->val + carry;
                carry = x / 10;
                if (S == 0) {
                    S = p = new ListNode(x % 10);
                } else {
                    p->next = new ListNode(x % 10);
                    p = p->next;
                }
                l1 = l1->next;
            }
            while (l2 != 0) {
                int x = l2->val + carry;
                carry = x / 10;
                if (S == 0) {
                    S = p = new ListNode(x % 10);
                } else {
                    p->next = new ListNode(x % 10);
                    p = p->next;
                }
                l2 = l2->next;
            }
            if (carry) {
                int x = carry;
                carry = x / 10;
                if (S == 0) {
                    S = p = new ListNode(x % 10);
                } else {
                    p->next = new ListNode(x % 10);
                    p = p->next;
                }
            }
        }
        return S;
    }
};