class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: Optional[ListNode]
        :type n: int
        :rtype: Optional[ListNode]
        """
        # Create a dummy node, which simplifies edge cases like removing the head
        dummy = ListNode(0)
        dummy.next = head
        slow = dummy
        fast = dummy
        
        # Move fast pointer n steps ahead
        for _ in range(n + 1):
            fast = fast.next
        
        # Move both slow and fast pointers until fast reaches the end
        while fast:
            slow = slow.next
            fast = fast.next
        
        # Remove the nth node from the end
        slow.next = slow.next.next
        
        return dummy.next
