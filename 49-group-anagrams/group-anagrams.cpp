class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        
        // Step 1: Sort each word and use it as a key
        for (const string& word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());  // Sort letters
            anagramGroups[sortedWord].push_back(word);   // Group by sorted key
        }

        // Step 2: Collect results
        vector<vector<string>> result;
        for (const auto& group : anagramGroups) {
            result.push_back(group.second);
        }
        
        return result;
    }
};
