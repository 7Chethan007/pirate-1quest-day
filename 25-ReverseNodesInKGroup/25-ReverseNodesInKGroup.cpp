// Last updated: 3/25/2026, 9:07:52 AM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Helper: reverse a linked list and return new head
        auto reverseLinkedList = [](ListNode* h) -> ListNode* {
            ListNode* prev = nullptr;
            ListNode* curr = h;
            while (curr != nullptr) {
                ListNode* front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }
            return prev; // new head
        };

        // Helper: get the k-th node starting from node 'start'
        // If there are fewer than k nodes, returns nullptr
        auto getKthNode = [](ListNode* start, int k) -> ListNode* {
            if (!start) return nullptr;
            int steps = k - 1; // we are already on the 1st node
            ListNode* temp = start;
            while (temp != nullptr && steps > 0) {
                temp = temp->next;
                --steps;
            }
            return temp; // could be nullptr if not enough nodes
        };

        // Edge cases
        if (!head || k <= 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroupTail = dummy;  // tail of the previous processed group
        ListNode* groupHead = head;       // start node of the current group to process

        while (groupHead != nullptr) {
            // Find k-th node for current group
            ListNode* kTh = getKthNode(groupHead, k);
            if (kTh == nullptr) {
                // fewer than k nodes remain -> not reversed; we're done
                break;
            }

            // Save next group's head
            ListNode* nextGroupHead = kTh->next;

            // Disconnect current group
            kTh->next = nullptr;

            // Reverse current group; newHead is kTh, newTail is groupHead
            ListNode* newHead = reverseLinkedList(groupHead);
            ListNode* newTail = groupHead; // after reversal the original head becomes the tail

            // Connect previous group's tail to new head
            prevGroupTail->next = newHead;
            // Connect new tail to next group's head
            newTail->next = nextGroupHead;

            // Advance prevGroupTail and groupHead to next group
            prevGroupTail = newTail;
            groupHead = nextGroupHead;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
