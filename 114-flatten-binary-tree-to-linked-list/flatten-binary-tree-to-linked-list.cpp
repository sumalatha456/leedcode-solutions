class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->left);
        flatten(root->right);

        // Store right subtree
        TreeNode* tempRight = root->right;

        // Move left subtree to right
        root->right = root->left;
        root->left = nullptr;

        // Find the last node of the new right subtree
        TreeNode* curr = root;
        while (curr->right) curr = curr->right;

        // Attach original right subtree
        curr->right = tempRight;
    }
};
