#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
    int val;
    TreeNode *left;
    TreeNode *right;
   
class Solution {
public:
    unordered_map<int, int> sumFrequency;  // To store the frequency of each sum
    
    // Helper function to calculate the subtree sum
    int subtreeSum(TreeNode* node) {
        if (!node) return 0;  // Base case: if the node is null, return 0
        
        int leftSum = subtreeSum(node->left);  // Recursively find left subtree sum
        int rightSum = subtreeSum(node->right);  // Recursively find right subtree sum
        
        int totalSum = node->val + leftSum + rightSum;  // Total sum of the current subtree
        
        sumFrequency[totalSum]++;  // Update the frequency of this sum
        
        return totalSum;  // Return the sum of the current subtree
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        // Base case: if the tree is empty, return an empty vector
        if (!root) return {};
        
        subtreeSum(root);  // Start the subtree sum calculation
        
        // Find the maximum frequency of any sum
        int maxFreq = 0;
        for (const auto& entry : sumFrequency) {
            maxFreq = max(maxFreq, entry.second);
        }
        
        // Collect all sums that have the maximum frequency
        vector<int> result;
        for (const auto& entry : sumFrequency) {
            if (entry.second == maxFreq) {
                result.push_back(entry.first);
            }
        }
        
        return result;  // Return the result
    }
};
