#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        // Sort the strings to put the smallest and largest strings first and last
        sort(strs.begin(), strs.end());

        // Compare characters of the first and last strings in the sorted list
        string first_str = strs[0];
        string last_str = strs.back();
        int common_prefix_length = min(first_str.size(), last_str.size());

        for (int i = 0; i < common_prefix_length; ++i) {
            if (first_str[i] != last_str[i]) {
                return first_str.substr(0, i);
            }
        }

        return first_str.substr(0, common_prefix_length);
    }
};

