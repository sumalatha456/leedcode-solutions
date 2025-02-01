class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # Sort the array
        nums.sort()
        
        result = []
        
        # Iterate through the array, fixing one element at a time
        for i in range(len(nums) - 2):
            # Skip duplicate elements for 'i'
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            # Use two-pointer technique to find pairs that sum to the negative of nums[i]
            left, right = i + 1, len(nums) - 1
            
            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]
                
                if current_sum == 0:
                    # Found a valid triplet
                    result.append([nums[i], nums[left], nums[right]])
                    
                    # Skip duplicates for 'left' and 'right'
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    
                    # Move both pointers
                    left += 1
                    right -= 1
                elif current_sum < 0:
                    # We need a larger sum, so move the left pointer right
                    left += 1
                else:
                    # We need a smaller sum, so move the right pointer left
                    right -= 1
        
        return result
