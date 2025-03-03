class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        sort(nums.begin(), nums.end()); // Step 1: Sort to handle duplicates
        backtrack(nums, 0, currentSubset, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<int>& currentSubset, vector<vector<int>>& result) {
        result.push_back(currentSubset); // Add current subset to result

        for (int i = start; i < nums.size(); i++) {
            // Step 3: Skip duplicates (except for the first occurrence)
            if (i > start && nums[i] == nums[i - 1]) continue;

            currentSubset.push_back(nums[i]); // Include current number
            backtrack(nums, i + 1, currentSubset, result);
            currentSubset.pop_back(); // Backtrack
        }
    }
};
