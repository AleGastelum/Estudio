#include <iostream>
#include <vector>

void printArray(std::vector<int> arrayToPrint)
{
	std::cout << "Array to print: " << std::endl;

	for (int i = 0; i < arrayToPrint.size(); i++)
	{
		std::cout << arrayToPrint[i] << ", " << std::endl;
	}

	std::cout << std::endl;
}

void swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

std::vector<int> bubbleSortAscending(std::vector<int> numsArray)
{
	for (int i = 0; i < numsArray.size() - 1; i++)
	{
		for (int j = 1; j < numsArray.size() - i; j++)
		{
			if (numsArray[j - 1] > numsArray[j])
			{
				swap(numsArray[j - 1], numsArray[j]);
			}
		}
	}

	return numsArray;
}

std::vector<int> bubbleSortDescending(std::vector<int> numsArray)
{
	for (int i = 0; i < numsArray.size() - 1; i++)
	{
		for (int j = 1; j < numsArray.size() - i; j++)
		{
			if (numsArray[j - 1] < numsArray[j])
			{
				swap(numsArray[j - 1], numsArray[j]);
			}
		}
	}

	return numsArray;
}

int main()
{
	std::vector<int> unsortedArray = { 2, 8, 5, 3, 9, 4, 1 };
	std::vector<int> ascendingSortedArray = bubbleSortAscending(unsortedArray);
	// std::vector<int> descendingSortedArray = bubbleSortDescending(unsortedArray);
	std::vector<int> descendingSortedArray = bubbleSortDescending(ascendingSortedArray);

	printArray(unsortedArray);
	printArray(ascendingSortedArray);
	printArray(descendingSortedArray);
}