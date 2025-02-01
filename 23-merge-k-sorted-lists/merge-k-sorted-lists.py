import heapq

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[Optional[ListNode]]
        :rtype: Optional[ListNode]
        """
        # Create a min-heap
        heap = []
        
        # Push the first node of each list into the heap
        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(heap, (lists[i].val, i, lists[i]))
        
        # Create a dummy node to simplify the merge process
        dummy = ListNode(0)
        current = dummy
        
        # Process the heap
        while heap:
            # Pop the smallest element from the heap
            val, idx, node = heapq.heappop(heap)
            
            # Append the smallest node to the result
            current.next = node
            current = current.next
            
            # If the current node has a next node, push it to the heap
            if node.next:
                heapq.heappush(heap, (node.next.val, idx, node.next))
        
        return dummy.next
