/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 bool checkSym(TreeNode* left, TreeNode* right) {
     if ((!left) != (!right))
        return false;
    if (!left)
        return true;
    if (right->val != left->val)
        return false;
    return checkSym(left->left, right->right) && checkSym(left->right, right-> left);
 }
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return checkSym(root->left, root->right);
    }
};