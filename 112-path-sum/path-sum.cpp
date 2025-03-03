class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false; // Base case: empty tree
        
        // If it's a leaf node, check if targetSum matches
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        // Recur on left and right subtrees with updated targetSum
        int newTarget = targetSum - root->val;
        return hasPathSum(root->left, newTarget) || hasPathSum(root->right, newTarget);
    }
};
