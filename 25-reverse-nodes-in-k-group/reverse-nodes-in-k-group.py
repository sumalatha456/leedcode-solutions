class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        # Base case: if the list is empty or k == 1, no reversal needed
        if not head or k == 1:
            return head
        
        # Helper function to reverse a segment of the list
        def reverse_linked_list(start, end):
            prev, curr = None, start
            while curr != end:
                next_node = curr.next
                curr.next = prev
                prev = curr
                curr = next_node
            return prev
        
        # Check if there are at least k nodes to reverse
        def has_k_nodes(start, k):
            current = start
            count = 0
            while current and count < k:
                current = current.next
                count += 1
            return count == k
        
        # Create a dummy node to make the head manipulation easier
        dummy = ListNode(0)
        dummy.next = head
        group_prev = dummy  # This will point to the node before the group we're reversing
        
        while head:
            if has_k_nodes(head, k):
                # Find the k-th node to reverse up to
                group_end = head
                for _ in range(k - 1):
                    group_end = group_end.next
                
                # Save the next node to connect later
                next_group_start = group_end.next
                
                # Reverse the k nodes
                group_start = head
                group_end.next = None  # Mark the end of the group
                
                # Reverse the group
                reversed_group = reverse_linked_list(group_start, None)
                
                # Connect the reversed group to the previous part
                group_prev.next = reversed_group
                group_start.next = next_group_start
                
                # Move group_prev to the end of the reversed group
                group_prev = group_start
                head = next_group_start
            else:
                break
        
        return dummy.next
