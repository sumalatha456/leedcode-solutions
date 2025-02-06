class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a new dummy node which will help in handling edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Current pointer to traverse the list
        ListNode* current = dummy;
        
        // Traverse through the list
        while (current->next != nullptr) {
            // If the next node has the target value, remove it
            if (current->next->val == val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; // Free the memory of the removed node
            } else {
                current = current->next; // Otherwise move to the next node
            }
        }
        
        // The new head of the list is dummy->next
        ListNode* newHead = dummy->next;
        delete dummy; // Free the dummy node
        return newHead;
    }
};
