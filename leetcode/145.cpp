/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void rec(TreeNode *root, vector<int>& v) {
        if (root) {
            rec(root->left, v);
            rec(root->right, v);
            v.push_back(root->val);
        }
    }
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        rec(root, v);
        return v;
    }
};