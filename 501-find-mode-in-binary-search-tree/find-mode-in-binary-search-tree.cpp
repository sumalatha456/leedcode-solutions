
class Solution {
public:
    void inorder(TreeNode* root, unordered_map<int, int>& freq_map) {
        if (!root) return;
        
        inorder(root->left, freq_map);
        freq_map[root->val]++;
        inorder(root->right, freq_map);
    }
    
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freq_map;
        inorder(root, freq_map);
        
        int max_freq = 0;
        // Find the maximum frequency
        for (auto& entry : freq_map) {
            max_freq = max(max_freq, entry.second);
        }
        
        vector<int> modes;
        // Collect all numbers with the maximum frequency
        for (auto& entry : freq_map) {
            if (entry.second == max_freq) {
                modes.push_back(entry.first);
            }
        }
        
        return modes;
    }
};
