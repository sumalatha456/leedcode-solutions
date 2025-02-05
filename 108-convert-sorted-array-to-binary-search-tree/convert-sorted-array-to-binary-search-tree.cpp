#include <vector>


using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }

    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;  // Base case: no elements to form a node
        }

        // Find the middle element
        int mid = left + (right - left) / 2;

        // Create the node with the middle element
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively build the left and right subtrees
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }
};
