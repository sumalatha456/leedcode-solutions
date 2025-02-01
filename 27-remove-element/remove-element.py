class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        j = 0  # Pointer for the next position to fill
        
        for i in range(len(nums)):
            if nums[i] != val:
                nums[j] = nums[i]  # Move the element to the "next available" position
                j += 1
        
        # After the loop, `j` is the new length of the array with the removed elements
        return j
