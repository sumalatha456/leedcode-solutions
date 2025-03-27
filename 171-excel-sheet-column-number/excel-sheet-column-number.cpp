class Solution {
public:
    int titleToNumber(string columnTitle) {
        int columnNumber = 0;
        
        for (char ch : columnTitle) {
            int charValue = ch - 'A' + 1;  // Convert 'A'-'Z' to 1-26
            columnNumber = columnNumber * 26 + charValue;
        }
        
        return columnNumber;
    }
};
