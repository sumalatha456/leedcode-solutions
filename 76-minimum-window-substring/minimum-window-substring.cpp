#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        // Frequency map for characters in t
        unordered_map<char, int> tFreq, windowFreq;
        for (char c : t) {
            tFreq[c]++;
        }
        
        int required = tFreq.size(); // Number of unique characters in t that need to be in the window
        int formed = 0;  // Number of unique characters in the current window that match the desired frequency
        int left = 0, right = 0; // Left and right pointers for the sliding window
        int minLen = INT_MAX; // Minimum window length
        int minLeft = 0; // Starting index of the minimum window

        // Start sliding the right pointer across the string
        while (right < s.length()) {
            char c = s[right];
            windowFreq[c]++;

            // If the current character's frequency in window matches the frequency in t
            if (tFreq.count(c) && windowFreq[c] == tFreq[c]) {
                formed++;
            }
            
            // When all required characters are found, try to shrink the window
            while (left <= right && formed == required) {
                char leftChar = s[left];

                // Update the minimum window if a smaller one is found
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                // Try to shrink the window from the left
                windowFreq[leftChar]--;
                if (tFreq.count(leftChar) && windowFreq[leftChar] < tFreq[leftChar]) {
                    formed--;
                }
                left++;
            }

            // Move the right pointer to expand the window
            right++;
        }
        
        // Return the minimum window found or empty string if no valid window
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};
