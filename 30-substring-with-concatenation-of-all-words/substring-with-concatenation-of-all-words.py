from collections import Counter

class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not s or not words or len(words[0]) == 0:
            return []
        
        word_len = len(words[0])  # Length of each word
        word_count = len(words)   # Number of words in words
        total_len = word_len * word_count  # Total length of concatenation
        word_map = Counter(words)  # Frequency map of words in the input list
        
        result = []
        
        # Try each possible starting point
        for i in range(word_len):  # Only need to check up to word_len different starting points
            left = i
            right = i
            current_map = Counter()  # To count the words in the current window
            
            while right + word_len <= len(s):  # Check if the window fits
                # Get the word at the current position
                word = s[right:right + word_len]
                
                # Move the right pointer
                right += word_len
                
                if word in word_map:
                    # Add the word to current map
                    current_map[word] += 1
                    
                    # If we have more of that word than we need, move the left pointer
                    while current_map[word] > word_map[word]:
                        left_word = s[left:left + word_len]
                        current_map[left_word] -= 1
                        left += word_len
                    
                    # If the window has the correct number of words, record the result
                    if right - left == total_len:
                        result.append(left)
                else:
                    # If the word is not in the list, reset the window
                    current_map.clear()
                    left = right
        
        return result
