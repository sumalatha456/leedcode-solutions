class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;  // Single node is always a palindrome

        // Step 1: Find middle using slow & fast pointers
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalf = reverseList(slow);

        // Step 3: Compare both halves
        ListNode* firstHalf = head;
        ListNode* temp = secondHalf;
        bool isPalin = true;
        
        while (temp) {
            if (firstHalf->val != temp->val) {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        // Step 4: Restore original list (optional)
        reverseList(secondHalf);
        
        return isPalin;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
};
