class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: If root is NULL, or root matches either p or q, return root
        if (!root || root == p || root == q) {
            return root;
        }

        // Recur on left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are non-null, root is the LCA
        if (left && right) {
            return root;
        }

        // Otherwise, return the non-null side (either left or right)
        return left ? left : right;
    }
};
