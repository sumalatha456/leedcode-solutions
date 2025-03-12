#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;  // Edge case: Empty tree
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;  // Track direction of zigzag
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Insert values in normal or reverse order based on `leftToRight`
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->val;

                // Add child nodes to queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(level);
            leftToRight = !leftToRight;  // Toggle direction for next level
        }
        
        return result;
    }
};
