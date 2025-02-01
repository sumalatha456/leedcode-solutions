class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        # Check if the lengths of s1, s2, and s3 are compatible
        if len(s1) + len(s2) != len(s3):
            return False
        
        # Initialize a 2D DP array with False values
        dp = [[False] * (len(s2) + 1) for _ in range(len(s1) + 1)]
        
        # Base case: an empty s1 and s2 can form an empty s3
        dp[0][0] = True
        
        # Fill the DP table
        for i in range(len(s1) + 1):
            for j in range(len(s2) + 1):
                # Check if the character from s1 can match the character in s3
                if i > 0 and s1[i - 1] == s3[i + j - 1]:
                    dp[i][j] = dp[i][j] or dp[i - 1][j]
                
                # Check if the character from s2 can match the character in s3
                if j > 0 and s2[j - 1] == s3[i + j - 1]:
                    dp[i][j] = dp[i][j] or dp[i][j - 1]
        
        # The final result is in dp[len(s1)][len(s2)]
        return dp[len(s1)][len(s2)]

        