class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = [-1]  # Initialize stack with -1 to handle edge cases
        max_length = 0
        
        for i in range(len(s)):
            if s[i] == '(':  # Push the index of '(' onto the stack
                stack.append(i)
            else:  # Encountered a ')'
                stack.pop()  # Pop the last '(' index
                if stack:
                    # Calculate the length of the valid substring
                    max_length = max(max_length, i - stack[-1])
                else:
                    # If stack is empty, push the current index as a base for future valid substrings
                    stack.append(i)
        
        return max_length

        