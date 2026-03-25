// Last updated: 3/25/2026, 9:06:59 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function: check if two subtrees are mirrors
    bool isMirror(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        if (p->val != q->val) return false;

        // Compare left subtree of p with right subtree of q, and vice versa
        return isMirror(p->left, q->right) &&
               isMirror(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;  // Empty tree is symmetric
        return isMirror(root->left, root->right);
    }
};
