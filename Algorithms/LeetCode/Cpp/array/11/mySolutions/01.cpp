// 11. Container with most water
// Brute Force approach, it works but does not pass all tests due to time limit exceeded

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& heights) {
        int distanceFromPoints = 0;
        int shortestPoint = 0;
        int area = 0;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            for (int j = i + 1; j < heights.size(); j++)
            {
                distanceFromPoints = j - i;
                shortestPoint = std::min(heights[i], heights[j]);
                area = distanceFromPoints * shortestPoint;
                
                maxArea = std::max(area, maxArea);
            }
        }
        
        return maxArea;
    }
};