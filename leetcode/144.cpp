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
    void pre(TreeNode* root, vector<int>& v) {
        if (root) {
            v.push_back(root->val);
            pre(root->left, v);
            pre(root->right, v);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v;
        pre(root, v);
        return v;
    }
};