/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countIter(TreeNode* root) {
        /* TLE !! */
        int count = 0;
        if (!root) return 0;
        deque<TreeNode*> Q;
        Q.push_back(root);
        while (!Q.empty()) {
            TreeNode* x = Q.front();
            Q.pop_front();
            if (x->left) Q.push_back(x->left);
            if (x->right) Q.push_back(x->right);
            count++;
        }
        return count;
    }

    int countNodesLeft(TreeNode* tmp) {
        int count_left = 0;
        while (tmp) {
            count_left++;
            tmp = tmp->left;
        }
        return count_left;
    }    

    int countNodesRight(TreeNode* tmp) {
        int count_right = 0;
        while (tmp) {
            count_right++;
            tmp = tmp->right;
        }
        return count_right;
    }

    int countNodes(TreeNode* root) { 
        if (!root) return 0;
        int count_left = countNodesLeft(root), count_right = countNodesRight(root);        
        if (count_left == count_right) return (2<<(count_left - 1)) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);        
    }
};
