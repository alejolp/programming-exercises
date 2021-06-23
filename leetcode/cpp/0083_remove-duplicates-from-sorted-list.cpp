/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* aux = head;
        while (aux) {
            while (aux->next && aux->val == aux->next->val) {
                aux->next = aux->next->next;
            }
            aux = aux->next;
        }
        return head;
    }
};