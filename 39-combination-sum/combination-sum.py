class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        # Result list to store valid combinations
        result = []
        
        # Backtracking helper function
        def backtrack(start, target, current_combination):
            # If the target becomes zero, we've found a valid combination
            if target == 0:
                result.append(list(current_combination))
                return
            
            for i in range(start, len(candidates)):
                # If the current candidate exceeds the target, no need to continue
                if candidates[i] > target:
                    continue
                
                # Include the current candidate in the combination and recurse
                current_combination.append(candidates[i])
                backtrack(i, target - candidates[i], current_combination)  # We allow reusing the same candidate
                current_combination.pop()  # Backtrack by removing the last added element
        
        # Sort candidates to help with pruning (optional, but useful for optimization)
        candidates.sort()
        
        # Start backtracking with the first candidate, target, and an empty current_combination
        backtrack(0, target, [])
        
        return result

        