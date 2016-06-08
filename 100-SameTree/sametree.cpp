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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((!p) && (!q))
            return true;
        if ((!p) != (!q))
            return false;
        if (p->val != q->val)
            return false;
        bool left = true;
        bool right = true;
        if ((p->left) && (q->left)) {
            if (p->left->val != q->left->val)
                return false;
            else
                left = isSameTree(p->left, q->left);
        } else if ((p->left) != (q->left)) {
            return false;
        }
         if ((p->right) && (q->right)) {
            if (p->right->val != q->right->val)
                return false;
            else
                right = isSameTree(p->right, q->right);
        } else if ((p->right) != (q->right)) {
            return false;
        }
        
        return left && right;
        
        
    }
};