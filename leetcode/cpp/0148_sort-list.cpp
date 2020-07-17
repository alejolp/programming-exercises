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
    ListNode *sortList(ListNode *head) {
        ListNode* p = head;
        vector<int> V;
        while (p) {
            V.push_back(p->val);
            p = p->next;
        }
        sort(V.begin(), V.end());
        p = head;
        int i = 0;
        while (p) {
            p->val = V[i];
            i++;
            p=p->next;
        }
        return head;
    }
};