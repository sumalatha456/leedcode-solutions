class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: Optional[TreeNode]
        :type q: Optional[TreeNode]
        :rtype: bool
        """
        
        # If both nodes are None, the trees are identical
        if not p and not q:
            return True
        
        # If one of the nodes is None and the other is not, trees are not identical
        if not p or not q:
            return False
        
        # If the values of the current nodes are different, trees are not identical
        if p.val != q.val:
            return False
        
        # Recursively compare the left subtree and right subtree
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
