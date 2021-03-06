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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return NULL;
        TreeNode* temp = root->left; root->left = root->right; root->right = temp; // swapping
        invertTree(root->left); invertTree(root->right); // recursion.
        return root;
    }
};