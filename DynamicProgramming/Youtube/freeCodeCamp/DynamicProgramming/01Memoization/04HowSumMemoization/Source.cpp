#include <iostream>
#include <vector>
#include <unordered_map>

// Global variables
std::unordered_map<int, std::vector<int>> foundResults;
std::vector<std::vector<int>> result;
// std::vector<int> numbersArray = { 2, 3 };
// std::vector<int> numbersArray = { 5, 3, 4, 7 };
// std::vector<int> numbersArray = { 2, 4 };
// std::vector<int> numbersArray = { 2, 3, 5 };
std::vector<int> numbersArray = { 7, 14 };


// Main functions
std::vector<int> howSum(int targetSum, std::vector<int> currentSum = {}, int currentElement = -1);
void printVector(std::vector<int> vector);

int main()
{
	// std::vector<int> result = howSum(7);
	// std::vector<int> result = howSum(8);
	std::vector<int> result = howSum(300);

	if (result.size() > 0)
	{
		printVector(result);
	}
	else
	{
		std::cout << "Null" << std::endl;
	}

	return 0;
}

void printVector(std::vector<int> vector)
{
	std::cout << "[ ";

	for (int element : vector)
	{
		std::cout << element << ",";
	}

	std::cout << " ]" << std::endl;
}

std::vector<int> howSum(int targetSum, std::vector<int> currentSum, int currentElement)
{
	if (foundResults.count(targetSum))
	{
		return foundResults[targetSum];
	}

	if (targetSum == 0)
	{
		currentSum.push_back(currentElement);
		return currentSum;
	}

	if (targetSum < 0)
	{
		return {};
	}

	for (int element : numbersArray)
	{
		int remainder = targetSum - element;
		std::vector<int> remainderResult = howSum(remainder, currentSum, element);
		std::vector<int> temp;

		if (remainderResult.size() > 0)
		{
			for (int remainderElement : remainderResult)
			{
				temp.push_back(remainderElement);
			}

			if (remainder != 0)
			{
				temp.push_back(element);
			}

			foundResults[targetSum] = temp;

			return temp;
		}
	}

	foundResults[targetSum] = {};
	return {};
}