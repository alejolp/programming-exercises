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
        ListNode* tmp = 0, *head = 0;
        while (l1 && l2) {
            ListNode* mine;
            if (l1->val < l2->val) {
                mine = l1;
                l1 = l1->next;
            } else {
                mine = l2;
                l2 = l2->next;
            }
            if (!tmp) {
                head = tmp = mine;
            } else {
                tmp->next = mine;
                tmp = mine;
            }
            mine->next = 0;
        }
        while (l1) {
            ListNode* mine = l1;
            l1 = l1->next;
            if (!tmp) {
                head = tmp = mine;
            } else {
                tmp->next = mine;
                tmp = mine;
            }
            mine->next = 0;                        
        }
        while (l2) {
            ListNode* mine = l2;
            l2 = l2->next;
            if (!tmp) {
                head = tmp = mine;
            } else {
                tmp->next = mine;
                tmp = mine;
            }
            mine->next = 0;                        
        }
        return head;
    }
};