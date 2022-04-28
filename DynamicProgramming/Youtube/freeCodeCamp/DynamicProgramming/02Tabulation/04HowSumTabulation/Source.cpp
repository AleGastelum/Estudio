#include <iostream>
#include <vector>

// Main functions
std::vector<int> howSum(int targetSum, std::vector<int>& numbersVector);
void printVector(std::vector<int>& vector);

int main()
{
	//std::vector<int> numbersVector = { 2, 3 }; // [ 3, 2, 2]
	//std::vector<int> numbersVector = { 5, 3, 4, 7 }; // [4, 3]
	//std::vector<int> numbersVector = { 2, 4 }; // null
	//std::vector<int> numbersVector = { 2, 3, 5 }; // [ 2, 2, 2, 2]
	std::vector<int> numbersVector = { 7, 14 }; // null

	//std::vector<int> result = howSum(7, numbersVector);
	//std::vector<int> result = howSum(8, numbersVector);
	std::vector<int> result = howSum(300, numbersVector);

	printVector(result);

	return 0;
}

void printVector(std::vector<int>& vector)
{
	for (int element : vector)
	{
		std::cout << element << ", ";
	}
}

std::vector<int> howSum(int targetSum, std::vector<int>& numbersVector)
{
	// Tabulation table
	std::vector<int> temp = {};
	std::vector<std::pair<bool, std::vector<int>>> tabulationTable(targetSum + 1, std::make_pair(false, temp));
	tabulationTable[0].first = true;

	for (int i = 0; i <= targetSum; i++)
	{
		if (tabulationTable[i].first)
		{
			for (int number : numbersVector)
			{
				if (i + number <= targetSum)
				{
					tabulationTable[i + number].first = true;
					tabulationTable[i + number].second = {};

					for (int element : tabulationTable[i].second)
					{
						tabulationTable[i + number].second.push_back(element);
					}

					tabulationTable[i + number].second.push_back(number);
				}
			}
		}
	}

	return tabulationTable[targetSum].second;
}