#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result = "";
        
        // Traverse both strings from the right to the left
        while (i >= 0 || j >= 0 || carry) {
            int bit_a = (i >= 0) ? a[i] - '0' : 0;
            int bit_b = (j >= 0) ? b[j] - '0' : 0;
            
            int sum = bit_a + bit_b + carry;
            
            // Update the carry for the next iteration
            carry = sum / 2;
            
            // Append the current sum's binary bit to the result
            result += (sum % 2) + '0';
            
            i--;
            j--;
        }
        
        // Since we've added bits from right to left, we need to reverse the result
        reverse(result.begin(), result.end());
        
        return result;
    }
};