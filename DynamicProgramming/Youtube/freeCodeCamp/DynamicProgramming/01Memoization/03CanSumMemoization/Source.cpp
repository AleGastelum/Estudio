#include <iostream>
#include <unordered_map>

// Global variables
std::unordered_map<int, bool> exploredSums;

// Test arrays
int numbersArray[] = { 2, 3 };
// int numbersArray[] = { 5, 3, 4, 7 };
// int numbersArray[] = { 2, 4 };
// int numbersArray[] = { 2, 3, 5 };
// int numbersArray[] = { 7, 14 };

// Main functions
bool exploreArrayForSums(int targetSum);

int main()
{
	std::cout << "Result: " << exploreArrayForSums(7) << std::endl;
	// std::cout << "Result: " << exploreArrayForSums(8) << std::endl;
	// std::cout << "Result: " << exploreArrayForSums(300) << std::endl;

	return 0;
}

bool exploreArrayForSums(int targetSum)
{
	if (exploredSums.count(targetSum))
	{
		return exploredSums[targetSum];
	}

	if (targetSum == 0)
	{
		return true;
	}

	if (targetSum < 0)
	{
		return false;
	}

	for (int i = 0; i < (sizeof(numbersArray) / sizeof(numbersArray[0])); i++)
	{
		if (exploreArrayForSums(targetSum - numbersArray[i]))
		{
			exploredSums[targetSum] = true;
			return true;
		}
	}

	exploredSums[targetSum] = false;
	return false;
}