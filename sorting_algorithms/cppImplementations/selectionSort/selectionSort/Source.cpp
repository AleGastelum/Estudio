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

void swap(int& number1, int& number2)
{
	int temporal = number1;

	number1 = number2;
	number2 = temporal;
}

std::vector<int> selectionSortAscending(std::vector<int> numbersArray)
{
	for (int i = 0; i < numbersArray.size() - 1; i++)
	{
		int currentMinimum = i;

		for (int j = i + 1; j < numbersArray.size(); j++)
		{
			if (numbersArray[j] < numbersArray[currentMinimum])
			{
				currentMinimum = j;
			}
		}

		if (i != currentMinimum)
		{
			swap(numbersArray[i], numbersArray[currentMinimum]);
		}
	}

	return numbersArray;
}

std::vector<int> selectionSortDescending(std::vector<int> numbersArray)
{
	for (int i = 0; i < numbersArray.size() - 1; i++)
	{
		int currentMinimum = i;

		for (int j = i + 1; j < numbersArray.size(); j++)
		{
			if (numbersArray[j] > numbersArray[currentMinimum])
			{
				currentMinimum = j;
			}
		}

		if (i != currentMinimum)
		{
			swap(numbersArray[i], numbersArray[currentMinimum]);
		}
	}

	return numbersArray;
}

int main()
{
	std::vector<int> unsortedArray = { 2, 8, 5, 3, 9, 4 };
	std::vector<int> sortedArrayAscending = selectionSortAscending(unsortedArray);
	std::vector<int> sortedArrayDescending = selectionSortDescending(sortedArrayAscending);

	printArray(unsortedArray);
	printArray(sortedArrayAscending);
	printArray(sortedArrayDescending);

	return 0;
}