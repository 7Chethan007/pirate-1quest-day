// Last updated: 3/25/2026, 9:04:23 AM
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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0; 
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = root->val;
        int resLevel = 1;
        int level = 1;

        while(!q.empty()) {
            int size = q.size();
            int levelSum = 0;

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(levelSum > maxSum) {
                maxSum = levelSum;
                // Update the level ...? -> Use 2 int resLevel and level
                resLevel = level;
            }
            level++;  // Level updates everytime but resLevel not always
        }

        return resLevel;
        
    }
};