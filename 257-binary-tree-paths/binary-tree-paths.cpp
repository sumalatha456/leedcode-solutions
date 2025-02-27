class Solution {
public:
    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (!node) return;
        
        // Add the current node value to path
        path += to_string(node->val);
        
        // If it's a leaf node, add the path to the result
        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }
        
        // Otherwise, continue the path with "->"
        path += "->";
        dfs(node->left, path, result);
        dfs(node->right, path, result);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};
