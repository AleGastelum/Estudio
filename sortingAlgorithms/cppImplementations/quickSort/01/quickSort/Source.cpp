// logica basada del video: https://www.youtube.com/watch?v=MZaf_9IZCrc

#include <vector>
#include <iostream>

void printArray(std::vector<int> arrayToPrint)
{
	std::cout << "Array to print: " << std::endl;

	for (int i = 0; i < arrayToPrint.size(); i++)
	{
		std::cout << arrayToPrint[i] << ", " << std::endl;
	}

	std::cout << std::endl;
}

void swap(int &numero1, int &numero2)
{
	int temporal = numero1;
	numero1 = numero2;
	numero2 = temporal;
}

void quickSortAscending(std::vector<int> &numbersArray, int leftLimit, int rightLimit)
{
	if (rightLimit <= leftLimit)
	{
		return;
	}


	int pivot = numbersArray[rightLimit];
	int leftPointer = leftLimit;
	int rightPointer = leftLimit;

	while (rightPointer < rightLimit)
	{
		if (numbersArray[rightPointer] <= pivot)
		{
			swap(numbersArray[leftPointer], numbersArray[rightPointer]);
			leftPointer++;
		}

		rightPointer++;
	}

	swap(numbersArray[leftPointer], numbersArray[rightLimit]);

	quickSortAscending(numbersArray, leftLimit, leftPointer - 1);
	quickSortAscending(numbersArray, leftPointer, rightLimit);
}

void quickSortDescending(std::vector<int>& numbersArray, int leftLimit, int rightLimit)
{
	if (rightLimit <= leftLimit)
	{
		return;
	}


	int pivot = numbersArray[rightLimit];
	int leftPointer = leftLimit;
	int rightPointer = leftLimit;

	while (rightPointer < rightLimit)
	{
		if (numbersArray[rightPointer] >= pivot)
		{
			swap(numbersArray[leftPointer], numbersArray[rightPointer]);
			leftPointer++;
		}

		rightPointer++;
	}

	swap(numbersArray[leftPointer], numbersArray[rightLimit]);

	quickSortDescending(numbersArray, leftLimit, leftPointer - 1);
	quickSortDescending(numbersArray, leftPointer, rightLimit);
}

int main()
{
	std::vector<int> unsortedArray = { 2, 8, 15, 3, 9, 4, 2, 14, 13, 1, 7, 5, 6, 20 };
	std::vector<int> sortedArrayAscending = unsortedArray;
	std::vector<int> sortedArrayDescending = unsortedArray;

	quickSortAscending(sortedArrayAscending, 0, sortedArrayAscending.size() - 1);
	quickSortDescending(sortedArrayDescending, 0, sortedArrayAscending.size() - 1);

	printArray(unsortedArray);
	printArray(sortedArrayAscending);
	printArray(sortedArrayDescending);

	return 0;
}