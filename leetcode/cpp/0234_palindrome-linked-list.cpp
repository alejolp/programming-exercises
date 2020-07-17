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
    int len(ListNode* head) {
        int r = 0;
        while (head) {
            head = head->next;
            ++r;
        }
        return r;
    }

    ListNode* reverse(ListNode* half) {
        ListNode* revhalf = 0;
        while (half) {
            ListNode* tmp = half->next;
            half->next = revhalf;
            revhalf = half;
            half = tmp;
        }
        return revhalf;
    }

    bool isPalindrome(ListNode* head) {
        int listlen = len(head); // O(n)
        int i;
        bool result = true;
        ListNode *half = head, *halforig = 0, *headorig = head;

        if(listlen < 2) return true; // O(1)

        // O(n/2)
        for(i=0;i<listlen/2; ++i) {
            half = half->next;
        }

        if (listlen%2) {
            half = half->next;
        }

        // O(n/2)
        halforig = half;
        half = reverse(half);

        while (half && head) {
            if (half->val != head->val) result = false;
            half = half->next;
            head = head->next;
        }

        reverse(halforig);

        return result;
    }
};