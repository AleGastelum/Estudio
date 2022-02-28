#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> usedLetters;
        int longestSubstring = 0;
        int currentStringBeginning = 0;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (usedLetters.find(s[i]) != usedLetters.end() && usedLetters[s[i]] >= currentStringBeginning) 
            {
                currentStringBeginning = usedLetters[s[i]] + 1;
                usedLetters[s[i]] = i;
            }
            
            longestSubstring = std::max(longestSubstring, i - currentStringBeginning + 1);
            usedLetters[s[i]] = i;
        }
        
        return longestSubstring;
    }
};