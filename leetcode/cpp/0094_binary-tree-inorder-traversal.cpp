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
    void inorder(TreeNode *root, vector<int>& v) {
        if (root) {
            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right, v);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
        inorder(root, v);
        return v;
    }
};