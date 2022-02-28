// Solution using the expand from the middle approach

#include <string>

class Solution {
public:
    int expandFromMiddle(std::string s, int beginning, int end)
    {
        while (beginning >= 0 && end < s.size() && s[beginning] == s[end])
        {   
            beginning--;
            end++;
        }
        
        return end - beginning - 1;
    }
    
    std::string longestPalindrome(std::string s)
    {
        if (s.size() < 1)
        {
            return "";
        }
        
        int beginning = 0;
        int stringLength = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            int lengthPrimePalindrome = expandFromMiddle(s, i, i);
            int lengthPairPalindrome = expandFromMiddle(s, i, i + 1);
            
            int maxLength = std::max(lengthPrimePalindrome, lengthPairPalindrome);
            
            if (maxLength > stringLength) 
            {
                beginning = i - ((maxLength - 1) / 2);
                stringLength = maxLength;
            }
        }

        return s.substr(beginning, stringLength);
    }
};