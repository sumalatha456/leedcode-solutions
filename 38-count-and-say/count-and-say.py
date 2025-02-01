class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        # Starting point of the sequence
        result = "1"
        
        # Generate the sequence for each step from 2 to n
        for _ in range(1, n):
            next_result = ""
            count = 1
            
            # Traverse the current result and count consecutive digits
            for i in range(1, len(result)):
                if result[i] == result[i - 1]:
                    count += 1  # Increment count if same digit
                else:
                    # When the digit changes, append count and digit to next_result
                    next_result += str(count) + result[i - 1]
                    count = 1  # Reset count for the new digit
            
            # Append the last counted digit to next_result
            next_result += str(count) + result[-1]
            
            # Update the result for the next iteration
            result = next_result
        
        return result
