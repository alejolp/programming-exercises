/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == 0) return 0;
        RandomListNode *R=0, *p1=0, *p2=head;
        map<RandomListNode*, RandomListNode*> M;
        
        while (p2) {
            if (R == 0) {
                R = p1 = new RandomListNode(p2->label);
            } else {
                p1->next = new RandomListNode(p2->label);
                p1 = p1->next;
            }
            M[p2] = p1;
            p2 = p2->next;
        }
        
        p1 = R;
        p2 = head;
        while (p2) {
            p1->random = p2->random ? M[p2->random] : 0;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return R;
    }
};