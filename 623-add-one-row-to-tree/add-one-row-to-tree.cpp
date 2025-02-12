class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // If the depth is 1, create a new root and attach the current tree to it.
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        // Helper function to traverse and add the row at the correct depth.
        queue<TreeNode*> q;
        q.push(root);
        int currentDepth = 1;

        // Traverse until the level just before the target depth
        while (!q.empty()) {
            int size = q.size();
            currentDepth++;
            
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                if (currentDepth == depth) {
                    // Insert new nodes at this level.
                    TreeNode* leftChild = node->left;
                    TreeNode* rightChild = node->right;

                    // Add the new node with the given value.
                    node->left = new TreeNode(val);
                    node->left->left = leftChild;

                    node->right = new TreeNode(val);
                    node->right->right = rightChild;
                } else {
                    // Push the children of the node to the queue for further traversal.
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }

            // If we've reached the desired depth, stop.
            if (currentDepth == depth) break;
        }

        return root;
    }
};
