class Solution:
    def merge(self, nums1, m, nums2, n):
        # Start from the end of both arrays
        i, j, k = m - 1, n - 1, m + n - 1
        
        # While there are elements in both nums1 and nums2
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1
        
        # If there are any elements left in nums2, copy them
        while j >= 0:
            nums1[k] = nums2[j]
            j -= 1
            k -= 1

# Instantiate the Solution class and call the merge method
solution = Solution()
nums1 = [1, 2, 3, 0, 0, 0]
m = 3
nums2 = [2, 5, 6]
n = 3

# Call the merge function
solution.merge(nums1, m, nums2, n)

# Output the result
print(nums1)  # Output: [1, 2, 2, 3, 5, 6]
