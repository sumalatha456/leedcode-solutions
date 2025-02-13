class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int longestPath = 0;

        // Directions for up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Helper DFS function
        function<int(int, int)> dfs = [&](int x, int y) -> int {
            // If already calculated, return the cached value
            if (dp[x][y] != 0) return dp[x][y];
            
            int maxLength = 1; // The minimum path length is 1 (the cell itself)
            
            // Explore the 4 possible directions
            for (auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;
                
                // Check bounds and if the next cell is greater than the current one
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > matrix[x][y]) {
                    maxLength = max(maxLength, 1 + dfs(nx, ny));
                }
            }
            
            // Memoize the result
            dp[x][y] = maxLength;
            return dp[x][y];
        };
        
        // Iterate over all cells and perform DFS to find the longest path
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                longestPath = max(longestPath, dfs(i, j));
            }
        }
        
        return longestPath;
    }
};
