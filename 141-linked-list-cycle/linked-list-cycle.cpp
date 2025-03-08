class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false; // Edge case: empty list or single node
        
        ListNode *slow = head, *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;          // Move slow by 1 step
            fast = fast->next->next;    // Move fast by 2 steps
            
            if (slow == fast) return true; // Cycle detected
        }
        
        return false; // No cycle
    }
};

