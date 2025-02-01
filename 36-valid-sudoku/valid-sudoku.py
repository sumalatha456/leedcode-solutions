class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        # Create three sets to track the numbers we've seen
        rows = [set() for _ in range(9)]  # Track numbers seen in each row
        cols = [set() for _ in range(9)]  # Track numbers seen in each column
        subgrids = [set() for _ in range(9)]  # Track numbers seen in each 3x3 subgrid
        
        # Iterate through each cell in the board
        for i in range(9):
            for j in range(9):
                num = board[i][j]
                
                if num != '.':  # Ignore empty cells
                    # Calculate subgrid index (i // 3) * 3 + j // 3
                    subgrid_index = (i // 3) * 3 + j // 3
                    
                    # Check if the number is already seen in the current row, column, or subgrid
                    if num in rows[i] or num in cols[j] or num in subgrids[subgrid_index]:
                        return False
                    
                    # Add the number to the respective row, column, and subgrid sets
                    rows[i].add(num)
                    cols[j].add(num)
                    subgrids[subgrid_index].add(num)
        
        # If no duplicates were found, return True
        return True

        