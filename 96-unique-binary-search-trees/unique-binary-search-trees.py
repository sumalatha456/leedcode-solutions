class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        # dp array to store the number of unique BSTs for each number of nodes
        dp = [0] * (n + 1)
        
        # Base case: an empty tree or a tree with one node has exactly 1 unique BST
        dp[0] = 1
        dp[1] = 1
        
        # Fill the dp array for all values from 2 to n
        for i in range(2, n + 1):
            for j in range(1, i + 1):
                dp[i] += dp[j - 1] * dp[i - j]
        
        # The result for n nodes is stored in dp[n]
        return dp[n]
