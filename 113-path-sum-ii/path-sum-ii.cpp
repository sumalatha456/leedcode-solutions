class Solution {
public:
    vector<vector<int>> result;
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return result;
    }

private:
    void dfs(TreeNode* node, int target, vector<int>& path) {
        if (!node) return;  // Base case: Empty node

        path.push_back(node->val);  // Add current node to path
        target -= node->val;  // Reduce target sum

        // If it's a leaf node and sum matches, store the path
        if (!node->left && !node->right && target == 0) {
            result.push_back(path);
        }

        // Recursive DFS for left and right children
        dfs(node->left, target, path);
        dfs(node->right, target, path);

        path.pop_back();  // Backtrack to explore other paths
    }
};
