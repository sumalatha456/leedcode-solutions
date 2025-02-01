class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # Sort the array to use two pointers
        nums.sort()
        
        # Initialize the result to be a large number
        closest_sum = float('inf')
        
        # Iterate over the array, considering each number as the first element
        for i in range(len(nums) - 2):
            # Skip duplicate values for 'i' to avoid redundant triplets
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            left, right = i + 1, len(nums) - 1
            
            # Use two-pointer approach to find the closest sum
            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]
                
                # If the current sum is exactly the target, return it
                if current_sum == target:
                    return current_sum
                
                # Update the closest_sum if the current sum is closer to the target
                if abs(current_sum - target) < abs(closest_sum - target):
                    closest_sum = current_sum
                
                # Move the pointers
                if current_sum < target:
                    left += 1
                else:
                    right -= 1
        
        return closest_sum
