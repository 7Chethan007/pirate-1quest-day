// Last updated: 3/25/2026, 9:06:51 AM
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;     // Edge case: empty tree

        queue<TreeNode*> q;           // Queue for BFS (level order traversal)
        q.push(root);                 // Start with root node
        int depth = 1;
        while (!q.empty()) {
            int size = q.size();      // Number of nodes in the current level
            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); // Get the front node
                q.pop();                    // Remove it from the queue

                if(node->left == nullptr && node->right == nullptr) {
                    return depth;
                }
                // Add child nodes to the queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }

        return depth;
    }
};