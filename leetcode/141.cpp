/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    typedef ListNode * ListNodePtr;
    void next(ListNodePtr& p) {
        if (p) p = p->next;
    }
public:
    bool hasCycle(ListNode *head) {
        ListNodePtr p1 = head;
        ListNodePtr p2 = head;
        if (!head) return false;
        next(p1);
        next(p2); next(p2);
        while (p1 && p2) {
            if (p1 == p2) return true;
            next(p1);
            next(p2); next(p2);
        }
        return false;
    }
};