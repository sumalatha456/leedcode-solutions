#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;  // Base case: Empty list
        
        return buildBST(head, nullptr);
    }

private:
    TreeNode* buildBST(ListNode* head, ListNode* tail) {
        if (head == tail) return nullptr;  // Base case: Empty range
        
        ListNode* mid = findMiddle(head, tail);
        TreeNode* root = new TreeNode(mid->val);
        
        root->left = buildBST(head, mid);  // Left half (before mid)
        root->right = buildBST(mid->next, tail);  // Right half (after mid)

        return root;
    }

    ListNode* findMiddle(ListNode* head, ListNode* tail) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};
