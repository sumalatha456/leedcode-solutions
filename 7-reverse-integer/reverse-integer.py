class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        # Handle negative numbers by remembering the sign
        sign = -1 if x < 0 else 1
        x *= sign  # Make x positive for the reversal
        
        # Reverse the digits and convert back to integer
        reversed_x = int(str(x)[::-1])
        
        # Reapply the sign
        reversed_x *= sign
        
        # Check if reversed_x is within the 32-bit signed integer range
        if reversed_x < -2**31 or reversed_x > 2**31 - 1:
            return 0
        
        return reversed_x
