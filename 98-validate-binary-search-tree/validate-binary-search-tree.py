class Solution(object):
    def isValidBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        
        # Helper function to perform recursive check with bounds
        def helper(node, lower=float('-inf'), upper=float('inf')):
            if not node:
                return True
            
            val = node.val
            if val <= lower or val >= upper:
                return False  # Node's value is outside of the valid range
            
            # Recursively check left subtree and right subtree with updated bounds
            return helper(node.left, lower, val) and helper(node.right, val, upper)
        
        return helper(root)
