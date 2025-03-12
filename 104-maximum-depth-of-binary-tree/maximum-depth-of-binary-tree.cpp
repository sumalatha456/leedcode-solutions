class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;  // Base case: If the tree is empty, depth is 0.
        
        int leftDepth = maxDepth(root->left);   // Recur for left subtree
        int rightDepth = maxDepth(root->right); // Recur for right subtree
        
        return max(leftDepth, rightDepth) + 1;  // Take max depth and add 1 for the current node
    }
};
