#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right = right & (right - 1); // Reduce right by clearing its least significant 1-bit
        }
        return left & right; // Return the bitwise AND of left and right
    }
};
