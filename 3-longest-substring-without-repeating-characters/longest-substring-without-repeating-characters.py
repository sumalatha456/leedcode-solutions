class Solution:
    def lengthOfLongestSubstring(self, s):
        char_set = set()  # Set to store unique characters in the window
        left = 0  # Left pointer of the window
        max_len = 0  # To track the maximum length of substring without repeating characters

        for right in range(len(s)):
            # If the character is in the set, move left pointer to the right of the duplicate character
            while s[right] in char_set:
                char_set.remove(s[left])
                left += 1
            # Add the character at right to the set
            char_set.add(s[right])
            # Update the max_len
            max_len = max(max_len, right - left + 1)

        return max_len

# Driver code
if __name__ == "__main__":
    solution = Solution()  # Create an instance of Solution
    param_1 = "abcabcbb"
    print(solution.lengthOfLongestSubstring(param_1))  # Call the method with a string parameter
