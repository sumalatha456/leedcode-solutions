class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        # Step 1: Find the largest index i such that nums[i] < nums[i + 1]
        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        
        # If i is valid, find the largest index j such that nums[j] > nums[i]
        if i >= 0:
            j = len(nums) - 1
            while nums[j] <= nums[i]:
                j -= 1
            # Swap nums[i] and nums[j]
            nums[i], nums[j] = nums[j], nums[i]
        
        # Step 2: Reverse the sequence from nums[i + 1] to the end
        nums[i + 1:] = reversed(nums[i + 1:])
