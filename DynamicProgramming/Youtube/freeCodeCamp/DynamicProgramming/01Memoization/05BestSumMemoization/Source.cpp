#include <iostream>
#include <unordered_map>
#include <vector>

enum ROUTE_EXISTENCE
{
	NO_ROUTE,
	ROUTE
};

// Global variables
std::unordered_map<int, std::pair<std::vector<int>, int>> foundRoutes;
std::vector<int> numbersVector = { 5, 3, 4, 7 };
//std::vector<int> numbersVector = { 2, 3, 5 };
//std::vector<int> numbersVector = { 1, 4, 5 };
//std::vector<int> numbersVector = { 1, 2, 5, 25 };

// Main functions
std::pair<std::vector<int>, int> bestSum(int targetSum);

// Utility functions
void printPair(std::pair<std::vector<int>, int> pair);

int main()
{
	std::pair<std::vector<int>, int> bestPair = bestSum(7);
	//std::pair<std::vector<int>, int> bestPair = bestSum(8);
	//std::pair<std::vector<int>, int> bestPair = bestSum(100);

	printPair(bestPair);

	return 0;
}

void printPair(std::pair<std::vector<int>, int> pair)
{
	if (pair.second == ROUTE)
	{
		std::cout << "Route found length: " << pair.first.size() << std::endl;
		std::cout << "[ ";

		for (int number : pair.first)
		{
			std::cout << number << ", ";
		}

		std::cout << "]" << std::endl;
	}
	else
	{
		std::cout << "No Route found" << std::endl;
	}
}

// Best Sum with Memoization
std::pair<std::vector<int>, int> bestSum(int targetSum)
{
	if (foundRoutes.count(targetSum))
	{
		return foundRoutes[targetSum];
	}

	if (targetSum == 0)
	{
		return std::make_pair(std::vector<int> {}, ROUTE);
	}

	if (targetSum < 0)
	{
		return std::make_pair(std::vector<int> {}, NO_ROUTE);
	}

	std::vector<int> currentBestSum = {};
	int foundRoute = NO_ROUTE;

	for (int number : numbersVector)
	{
		int remainder = targetSum - number;
		std::pair<std::vector<int>, int> currentPair = bestSum(remainder);

		if (currentPair.second == ROUTE)
		{
			currentPair.first.push_back(number);

			if (currentBestSum.size() == 0 || currentPair.first.size() < currentBestSum.size())
			{
				currentBestSum = currentPair.first;
				foundRoute = ROUTE;
			}
		}
	}

	foundRoutes[targetSum] = std::make_pair(currentBestSum, foundRoute);
	return std::make_pair(currentBestSum, foundRoute);
}