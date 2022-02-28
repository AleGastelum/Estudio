// 11. Container with most water
// I managed to come with an O(n) solution

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& heights) {
        int maxArea  = 0;
        int currentArea = 0;
        int leftLinePosition = 0;
        int rightLinePosition = heights.size() - 1;
        int distanceBetweenLines = 0;
        int shortestLine = 0;
        
        while (leftLinePosition < rightLinePosition)
        {
            distanceBetweenLines = rightLinePosition - leftLinePosition;
            shortestLine = std::min(heights[rightLinePosition], heights[leftLinePosition]);
            currentArea = distanceBetweenLines * shortestLine;
            
            if (currentArea > maxArea)
            {
                maxArea = currentArea;
            }
            
            if (shortestLine == heights[leftLinePosition])
            {
                leftLinePosition++;
            }
            else
            {
                rightLinePosition--;
            }
        }
        
        return maxArea;
    }
};