class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        
        int left = 1, right = k + 1;
        // Create the first k distinct differences using alternating high-low sequence
        while (left <= right) {
            result.push_back(left++);
            if (left <= right) {
                result.push_back(right--);
            }
        }

        // Fill the rest of the numbers sequentially
        for (int i = k + 2; i <= n; ++i) {
            result.push_back(i);
        }

        return result;
    }
};
