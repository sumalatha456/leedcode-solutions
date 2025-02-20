class Solution {
public:
    void backtrack(int k, int n, int start, vector<int>& current, vector<vector<int>>& result) {
        // If we have selected k numbers and their sum equals n, we add the current combination to result.
        if (current.size() == k && n == 0) {
            result.push_back(current);
            return;
        }
        
        // If we've selected k numbers but the sum doesn't equal n, or if sum goes below zero, return.
        if (current.size() > k || n < 0) {
            return;
        }

        // Start from the current number and try adding numbers in the range [start, 9]
        for (int i = start; i <= 9; ++i) {
            current.push_back(i);
            // Recurse with reduced sum and incremented number count
            backtrack(k, n - i, i + 1, current, result);
            current.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(k, n, 1, current, result); // start from number 1
        return result;
    }
};
