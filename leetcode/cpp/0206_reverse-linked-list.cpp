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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = 0;
        while (head) {
            ListNode* e = head;
            head = head->next;
            e->next = p;
            p = e;
        }
        return p;
    }
};