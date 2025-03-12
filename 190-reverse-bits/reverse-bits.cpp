class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for (int i = 0; i < 32; i++) {
            result = (result << 1) | (n & 1);  // Shift left and add the last bit of n
            n >>= 1;  // Shift n to the right to process the next bit
        }
        
        return result;
    }
};
