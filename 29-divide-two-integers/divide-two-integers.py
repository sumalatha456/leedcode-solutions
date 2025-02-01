class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        # Edge case for overflow (min value can't be divided by -1)
        if dividend == -2147483648 and divisor == -1:
            return 2147483647
        
        # Determine if the result should be negative
        negative = (dividend < 0) != (divisor < 0)
        
        # Work with positive values for simplicity
        dividend = abs(dividend)
        divisor = abs(divisor)
        
        quotient = 0
        # Find the largest multiple of divisor that fits into dividend
        while dividend >= divisor:
            temp, multiple = divisor, 1
            while dividend >= (temp << 1):  # temp * 2
                temp <<= 1  # Double the temp (equivalent to temp * 2)
                multiple <<= 1  # Double the multiple (equivalent to multiple * 2)
            
            # Subtract the found multiple from dividend and add to quotient
            dividend -= temp
            quotient += multiple
        
        # Apply the sign of the result
        if negative:
            quotient = -quotient
        
        # Clamp the result to fit within the 32-bit signed integer range
        return max(min(quotient, 2147483647), -2147483648)
