class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        if (!node) return 0;  // Base case: Height of NULL node is 0

        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1;  // Left subtree is unbalanced

        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1;  // Right subtree is unbalanced

        if (abs(leftHeight - rightHeight) > 1) return -1;  // Current node is unbalanced

        return max(leftHeight, rightHeight) + 1;  // Return subtree height
    }
};
