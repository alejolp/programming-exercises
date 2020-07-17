/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool cmp(ListNode* a, ListNode* b) {
    int av = a ? a->val : INT_MIN;
    int bv = b ? b->val : INT_MIN;
    return bv < av;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = 0, *result = 0;

        make_heap(lists.begin(), lists.end(), cmp);

        while (lists.size()) {
            pop_heap(lists.begin(), lists.end(), cmp);
            ListNode* e = lists.back();
            lists.pop_back();

            if (!e) continue;

            if (!head) {
                result = head = e;
                e = e->next;
            } else {
                head->next = e;
                e = e->next;
                head = head->next;
            }
            head->next = 0;
            if (e) {
                lists.push_back(e);
                push_heap(lists.begin(), lists.end(), cmp);
            }
        }

        return result;
    }
};