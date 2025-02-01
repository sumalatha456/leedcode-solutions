class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        # First, sort the candidates to help with pruning duplicates
        candidates.sort()
        
        result = []
        
        def backtrack(start, target, current_combination):
            # If target is zero, we've found a valid combination
            if target == 0:
                result.append(list(current_combination))
                return
            
            for i in range(start, len(candidates)):
                # Skip duplicates: if the current element is the same as the previous one, skip it
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                
                # If the current number is greater than the remaining target, no need to continue
                if candidates[i] > target:
                    break
                
                # Include the current element in the combination and recurse
                current_combination.append(candidates[i])
                backtrack(i + 1, target - candidates[i], current_combination)
                
                # Backtrack: remove the last element and continue to the next possibility
                current_combination.pop()
        
        # Start backtracking from index 0
        backtrack(0, target, [])
        return result
