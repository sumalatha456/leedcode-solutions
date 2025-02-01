class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        def findFirst(nums, target):
            left, right = 0, len(nums) - 1
            first_pos = -1
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] == target:
                    first_pos = mid
                    right = mid - 1  # Move left to find the first occurrence
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return first_pos
        
        def findLast(nums, target):
            left, right = 0, len(nums) - 1
            last_pos = -1
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] == target:
                    last_pos = mid
                    left = mid + 1  # Move right to find the last occurrence
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid - 1
            return last_pos
        
        # Find the first and last positions
        first = findFirst(nums, target)
        if first == -1:  # If the first position is -1, the target is not found
            return [-1, -1]
        last = findLast(nums, target)
        
        return [first, last]
