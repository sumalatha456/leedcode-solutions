class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string new_s = s + "#" + rev_s;

        // Compute LPS array
        int n = new_s.length();
        vector<int> lps(n, 0);
        int j = 0;
        
        for (int i = 1; i < n; i++) {
            while (j > 0 && new_s[i] != new_s[j]) {
                j = lps[j - 1];
            }
            if (new_s[i] == new_s[j]) {
                j++;
            }
            lps[i] = j;
        }

        // The longest palindromic prefix length
        int palindromeLength = lps[n - 1];

        // Append remaining characters from reversed string to the front
        string toAdd = s.substr(palindromeLength);
        reverse(toAdd.begin(), toAdd.end());

        return toAdd + s;
    }
};
