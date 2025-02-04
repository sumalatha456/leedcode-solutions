class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        
        # Helper function to backtrack
        def backtrack(path, remaining):
            # If no more elements to permute, append the path as a result
            if not remaining:
                result.append(path)
                return
            
            # Iterate through all the remaining numbers and backtrack
            for i in range(len(remaining)):
                # Choose the number at index i
                new_path = path + [remaining[i]]
                new_remaining = remaining[:i] + remaining[i+1:]
                
                # Recursively permute with the new path and remaining numbers
                backtrack(new_path, new_remaining)
        
        # Start the backtracking with an empty path and all numbers remaining
        backtrack([], nums)
        return result
