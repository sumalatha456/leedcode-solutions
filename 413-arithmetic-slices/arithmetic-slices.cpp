class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; // At least 3 elements are needed for an arithmetic slice

        int count = 0;
        int curr = 0; // Stores the count of slices ending at the current index

        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                curr += 1;
                count += curr; // Add the current count to the total count
            } else {
                curr = 0; // Reset if the difference changes
            }
        }

        return count;
    }
};
