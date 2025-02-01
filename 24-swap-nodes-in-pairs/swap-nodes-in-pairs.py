class Solution(object):
    def swapPairs(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        # Create a dummy node to simplify the handling of head node
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy  # Previous node, initially pointing to dummy
        
        # Traverse the list in pairs
        while head and head.next:
            first = head  # First node in the pair
            second = head.next  # Second node in the pair
            
            # Swap the nodes
            prev.next = second  # Connect previous node to second
            first.next = second.next  # Connect first node to the next pair
            second.next = first  # Make second node point to first node
            
            # Move prev and head to the next pair
            prev = first
            head = first.next
        
        # Return the new head (which is the next of dummy)
        return dummy.next
