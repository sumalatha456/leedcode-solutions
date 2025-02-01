class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1 or numRows >= len(s):
            return s
        
        # Create a list of strings for each row
        rows = [''] * numRows
        current_row = 0
        going_down = False
        
        # Iterate through each character in the string
        for char in s:
            rows[current_row] += char
            
            # Change direction if we are at the top or bottom row
            if current_row == 0 or current_row == numRows - 1:
                going_down = not going_down
            
            # Move to the next row, either down or up
            current_row += 1 if going_down else -1
        
        # Concatenate all rows and return the result
        return ''.join(rows)
