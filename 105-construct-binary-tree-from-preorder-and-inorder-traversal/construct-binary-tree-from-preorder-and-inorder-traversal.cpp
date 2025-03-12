#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> inorderIndexMap;
    int preorderIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Store inorder indices for fast lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        return constructTree(preorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* constructTree(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr; // Base case: No elements to construct

        // Get root value from preorder and move index
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);

        // Get inorder index of root
        int inorderIndex = inorderIndexMap[rootValue];

        // Recursively construct left and right subtrees
        root->left = constructTree(preorder, left, inorderIndex - 1);
        root->right = constructTree(preorder, inorderIndex + 1, right);

        return root;
    }
};
