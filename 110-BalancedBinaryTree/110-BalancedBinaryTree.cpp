// Last updated: 3/25/2026, 9:06:53 AM
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
    int abso(int n) {
        return (n >= 0) ? n : -n;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        if(findHeight(root) == -1) return false;

        return true;
    }

    // bool checkHeight(TreeNode* root) {
    //     if(root == nullptr) return true;
    //     int lH = findHeight(root->left);
    //     int rH = findHeight(root->right);
    //     if(abso(lH-rH) > 1) return false;

    //     return checkHeight(root->left) && checkHeight(root->right);
    // }

    int findHeight(TreeNode* node) {
        if(node == nullptr) return 0;
        int left = findHeight(node->left);
        int right = findHeight(node->right);

        if(left == -1 || right == -1) return -1;

        if(abso(left - right) > 1) return -1;

        return 1 + max(left, right);
    }
};