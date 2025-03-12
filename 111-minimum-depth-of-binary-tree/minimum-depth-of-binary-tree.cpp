class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;  // Base case: Empty tree
        
        if (!root->left) return 1 + minDepth(root->right);  // Only right subtree exists
        if (!root->right) return 1 + minDepth(root->left);  // Only left subtree exists

        return 1 + min(minDepth(root->left), minDepth(root->right));  // Both subtrees exist
    }
};
