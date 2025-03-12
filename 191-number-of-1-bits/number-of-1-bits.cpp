class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            n &= (n - 1);  // Removes the lowest set bit
            count++;
        }
        return count;
    }
};
