#include <iostream>
#include <vector>

std::vector<int> insertionSortAscending(std::vector<int> numbersArray)
{
	for (int i = 1; i < numbersArray.size(); i++)
	{
		int newNumber = numbersArray[i];
		int j = i - 1;

		while (j >= 0 && numbersArray[j] > newNumber)
		{
			numbersArray[j + 1] = numbersArray[j];
			j--;
		}
		
		numbersArray[j + 1] = newNumber;
	}

	return numbersArray;
}

std::vector<int> insertionSortDescending(std::vector<int> numbersArray)
{
	for (int i = 1; i < numbersArray.size(); i++)
	{
		int newNumber = numbersArray[i];
		int j = i - 1;

		while (j >= 0 && numbersArray[j] < newNumber)
		{
			numbersArray[j + 1] = numbersArray[j];
			j--;
		}

		numbersArray[j + 1] = newNumber;
	}

	return numbersArray;
}

void printArray(std::vector<int> arrayToPrint)
{
	std::cout << "Array to print: " << std::endl;

	for (int i = 0; i < arrayToPrint.size(); i++)
	{
		std::cout << arrayToPrint[i] << ", " << std::endl;
	}

	std::cout << std::endl;
}

int main()
{
	std::vector<int> unsortedArray = { 2, 8, 5, 3, 9, 4 };
	std::vector<int> sortedArrayAscending = insertionSortAscending(unsortedArray);
	std::vector<int> sortedArrayDescending = insertionSortDescending(sortedArrayAscending);

	printArray(unsortedArray);
	printArray(sortedArrayAscending);
	printArray(sortedArrayDescending);

	return 0;
}