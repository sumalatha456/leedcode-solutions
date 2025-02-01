class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Step 1: Remove leading whitespaces
        s = s.lstrip()
        
        # Step 2: Handle empty string case after trimming
        if not s:
            return 0
        
        # Step 3: Initialize variables
        result = 0
        sign = 1
        i = 0
        
        # Step 4: Handle the sign (if any)
        if s[i] == '-':
            sign = -1
            i += 1
        elif s[i] == '+':
            i += 1
        
        # Step 5: Convert the number
        while i < len(s) and s[i].isdigit():
            result = result * 10 + int(s[i])
            i += 1
        
        # Step 6: Apply the sign to the result
        result *= sign
        
        # Step 7: Clamp the result to the 32-bit signed integer range
        if result < -2**31:
            return -2**31
        elif result > 2**31 - 1:
            return 2**31 - 1
        
        return result
