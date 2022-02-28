// NOTE: this code was ran on letcode page
// Main concept used - Map (unordered)

#include <vector>
#include <unordered_map>
#include <string>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> sumPairs;
        int complement;
        
        for (int i = 0; i < nums.size(); i++)
        {
            complement = target - nums[i];
            if (sumPairs.find(complement) != sumPairs.end())
            {
                return {
                    sumPairs[complement],
                    i
                };
            }
            
            sumPairs[nums[i]] = i;
        }
        
        return {};
    }
};