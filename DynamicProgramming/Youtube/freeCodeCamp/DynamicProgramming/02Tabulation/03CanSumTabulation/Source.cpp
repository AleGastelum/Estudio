#include <iostream>
#include <vector>

// Main functions
bool canSum(int targetSum, std::vector<int>& numbersVector);

int main()
{
	//std::vector<int> numbersVector = { 2, 3 }; // true
	//std::vector<int> numbersVector = { 5, 3, 4, 7 }; // true
	//std::vector<int> numbersVector = { 2, 4 }; // false
	//std::vector<int> numbersVector = { 2, 3, 5 }; // true
	std::vector<int> numbersVector = { 7, 14 }; // false

	bool didSum;

	//didSum = canSum(7, numbersVector);
	//didSum = canSum(8, numbersVector);
	didSum = canSum(300, numbersVector);

	if (didSum)
	{
		std::cout << "It did Sum" << std::endl;
	}
	else
	{
		std::cout << "It did not Sum" << std::endl;

	}

	return 0;
}

bool canSum(int targetSum, std::vector<int>& numbersVector)
{
	std::vector<bool> tabulationTable(targetSum + 1, false);
	tabulationTable[0] = true;

	for (int i = 0; i <= targetSum; i++)
	{
		if (tabulationTable[i])
		{
			for (int number : numbersVector)
			{
				if (i + number <= targetSum)
				{
					tabulationTable[i + number] = true;
				}
			}
		}
	}

	return tabulationTable[targetSum];
}