// Solution using the manacher's algorithm approach

#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::string createExpandedString(std::string originalS)
    {
        std::string expandedS = "";
        
        for (int i = 0; i < originalS.size(); i++)
        {
            expandedS += "#";
            expandedS += originalS[i];
        }
        expandedS += "#";
        
        return expandedS;
    }
    
    std::string longestPalindrome(std::string s)
    {
        if (s.size() < 1)
        {
            return "";
        }
        
        std::string expandedS = createExpandedString(s);
        std::vector<int> palindromes(expandedS.size());
        int palindromeCenter = 0;
        int palindromeRightLimit = 0;
        int mirrorPosition = 0;
        int maxPalindromePosition = 0;
        int maxPalindromeSize = 0;
        
        for (int i = 1; i < expandedS.size(); i++)
        {
            mirrorPosition = (2 * palindromeCenter) - i;
            
            if (i < palindromeRightLimit)
            {
                palindromes[i] = std::min(palindromeRightLimit - i, palindromes[mirrorPosition]);
            }
                
            int leftExpansion = i - (palindromes[i] + 1);
            int rightExpansion = i + (palindromes[i] + 1);
            while (leftExpansion >= 0 && leftExpansion < expandedS.size() && expandedS[leftExpansion] == expandedS[rightExpansion])
            {
                palindromes[i]++;
                leftExpansion--;
                rightExpansion++;
            }
            
            if ((palindromes[i] + i) > palindromeRightLimit)
            {
                palindromeCenter = i;
                palindromeRightLimit = i + palindromes[i];
            }
            
            if (palindromes[i] > maxPalindromeSize)
            {
                maxPalindromeSize = palindromes[i];
                maxPalindromePosition = i;
            }
        }
        
        
        std::string longestPalindrome = s.substr((maxPalindromePosition / 2) - (maxPalindromeSize / 2), maxPalindromeSize);
        
        return longestPalindrome;
    }
};