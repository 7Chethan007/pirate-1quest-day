// Last updated: 3/25/2026, 9:06:39 AM
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertCopyInBetween(Node* head) {
        Node* temp = head;
        while(temp != nullptr) {
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);

            copy->next = nextElement;
            temp->next = copy;
            temp = nextElement;
        }
    }

    void connectRandomPointers(Node* head) {
        Node *temp = head;
        while(temp != nullptr) {
            Node* copyNode = temp->next;
            if(temp->random){
                copyNode->random = temp->random->next;
            }
            else {
                copyNode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }

    Node* getDeepCopyList(Node* head) {
        Node* temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        while(temp != nullptr) {
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummyNode->next;
    }


    Node* copyRandomList(Node* head) {
        // If the original list
        // is empty, return null
        if(!head) return nullptr;   
        
        // Step 1: Insert copy of
        // nodes in between
        insertCopyInBetween(head); 
        // Step 2: Connect random
        // pointers of copied nodes
        connectRandomPointers(head);  
        // Step 3: Retrieve the deep
        // copy of the linked list
        return getDeepCopyList(head);
        
    }
};