// Last updated: 3/25/2026, 9:06:36 AM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find meeting point (if any)
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break; // cycle detected
        }

        // If no cycle, fast will be null or fast->next will be null
        if (!fast || !fast->next) return nullptr;

        // Move slow to head; keep fast at meeting point.
        // Each step they move one; the node where they meet is the cycle start.
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // start of cycle
    }
};
