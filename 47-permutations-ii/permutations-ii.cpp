class Solution {
public:
    vector<vector<int>> result;
    
    void backtrack(vector<int>& nums, vector<int>& temp, vector<bool>& visited) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // Skip already used numbers
            if (visited[i]) continue;

            // Skip duplicates (Only allow first unvisited duplicate in a level)
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            // Mark as visited and recurse
            visited[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums, temp, visited);
            temp.pop_back();
            visited[i] = false;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        vector<bool> visited(nums.size(), false);
        vector<int> temp;
        backtrack(nums, temp, visited);
        return result;
    }
};
