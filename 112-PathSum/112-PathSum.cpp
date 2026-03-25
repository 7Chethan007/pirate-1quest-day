// Last updated: 3/25/2026, 9:06:50 AM
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: empty tree
        if (!root) return false;

        // Subtract current node value from target sum
        targetSum -= root->val;

        // If we reached a leaf node, check if remaining sum is 0
        if (!root->left && !root->right) {
            return (targetSum == 0);
        }

        // Otherwise, check left or right subtree
        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};
