class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        backtrack(nums, 0, currentSubset, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, int index, vector<int>& currentSubset, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(currentSubset);
        
        // Explore further subsets by including the next elements
        for (int i = index; i < nums.size(); ++i) {
            currentSubset.push_back(nums[i]);           // Include the current element
            backtrack(nums, i + 1, currentSubset, result); // Recur for the next element
            currentSubset.pop_back();                   // Backtrack and remove the last element
        }
    }
};
