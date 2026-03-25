// Last updated: 3/25/2026, 9:06:55 AM
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;   // Final answer: list of levels
        if (!root) return result;     // Edge case: empty tree

        queue<TreeNode*> q;           // Queue for BFS (level order traversal)
        q.push(root);                 // Start with root node
        bool isForward = true;
        // Process nodes level by level
        while (!q.empty()) {
            int size = q.size();      // Number of nodes in the current level
            list<int> level;        // Store values of this level

            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); // Get the front node
                q.pop();                    // Remove it from the queue

                // level.push_back(node->val); // Add its value to this level

                if(isForward) level.push_back(node->val);
                else level.push_front(node->val);

                // Add child nodes to the queue for the next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            isForward = !isForward;

            // Convert list<int> to vector<int> and push to result
            result.push_back(vector<int>(level.begin(), level.end()));
        }

        return result;














        // void myReverse(vector<int> &arr, int size) {
        //     int start = 0;
        //     int end = size - 1;

        //     while (start < end) {
        //         // Swap elements at start and end
        //         int temp = arr[start];
        //         arr[start] = arr[end];
        //         arr[end] = temp;

        //         // Move the pointers
        //         start++;
        //         end--;
        //     }
        // }



        // vector<vector<int>> result;   // Final answer: list of levels
        // if (!root) return result;     // Edge case: empty tree

        // bool what = true;

        // queue<TreeNode*> q;           // Queue for BFS (level order traversal)
        // q.push(root);                 // Start with root node

        // // Process nodes level by level
        // while (!q.empty()) {
        //     int size = q.size();      // Number of nodes in the current level
        //     vector<int> level;        // Store values of this level

        //     // Process all nodes at the current level
        //     for (int i = 0; i < size; i++) {
        //         TreeNode* node = q.front(); // Get the front node
        //         q.pop();                    // Remove it from the queue

        //         level.push_back(node->val); // Add its value to this level

        //         // Add child nodes to the queue for the next level
        //         if (node->left) q.push(node->left);
        //         if (node->right) q.push(node->right);
        //     }

        //     // if what is true then as usual
        //     if(what) {
        //         result.push_back(level);  // Save this level into the result
        //     }
        //     else {
        //         // push to result in reverse order
        //         int n = level.size();
        //         myReverse(level,n);
        //         result.push_back(level);
        //     }
        //     // After 1st iteration make false
        //     what = !what;

        // }

        // return result;
    }
};