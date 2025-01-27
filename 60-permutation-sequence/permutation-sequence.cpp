#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }
        string result;
        k--; // Convert k to zero-indexed

        for (int i = n; i > 0; i--) {
            int fact = 1;
            for (int j = 1; j < i; j++) {
                fact *= j;
            }
            int index = k / fact;
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= fact;
        }
        return result;
    }
};

