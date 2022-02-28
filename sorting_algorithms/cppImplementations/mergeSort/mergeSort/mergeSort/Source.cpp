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

void mergeArraysAscending(std::vector<int>& numbersArray, int leftLimit, int middlePoint, int rightLimit)
{
	std::vector<int> leftArray;
	std::vector<int> rightArray;

	for (int i = leftLimit; i <= middlePoint; i++)
	{
		leftArray.push_back(numbersArray[i]);
	}

	for (int i = middlePoint + 1; i <= rightLimit; i++)
	{
		rightArray.push_back(numbersArray[i]);
	}

	int leftArrayPointer = 0;
	int rightArrayPointer = 0;
	int i = leftLimit;
	while (leftArrayPointer < leftArray.size() && rightArrayPointer < rightArray.size())
	{
		if (leftArray[leftArrayPointer] < rightArray[rightArrayPointer])
		{
			numbersArray[i] = leftArray[leftArrayPointer];
			leftArrayPointer++;
		}
		else
		{
			numbersArray[i] = rightArray[rightArrayPointer];
			rightArrayPointer++;
		}

		i++;
	}

	while (leftArrayPointer < leftArray.size())
	{
		numbersArray[i] = leftArray[leftArrayPointer];
		i++;
		leftArrayPointer++;
	}

	while (rightArrayPointer < rightArray.size())
	{
		numbersArray[i] = rightArray[rightArrayPointer];
		i++;
		rightArrayPointer++;
	}
}

void mergeArraysDescending(std::vector<int> &numbersArray, int leftLimit, int middlePoint, int rightLimit)
{
	std::vector<int> leftArray;
	std::vector<int> rightArray;

	for (int i = leftLimit; i <= middlePoint; i++)
	{
		leftArray.push_back(numbersArray[i]);
	}

	for (int i = middlePoint + 1; i <= rightLimit; i++)
	{
		rightArray.push_back(numbersArray[i]);
	}

	int leftArrayPointer = 0;
	int rightArrayPointer = 0;
	int i = leftLimit;
	while (leftArrayPointer < leftArray.size() && rightArrayPointer < rightArray.size())
	{
		if (leftArray[leftArrayPointer] > rightArray[rightArrayPointer])
		{
			numbersArray[i] = leftArray[leftArrayPointer];
			leftArrayPointer++;
		}
		else
		{
			numbersArray[i] = rightArray[rightArrayPointer];
			rightArrayPointer++;
		}

		i++;
	}

	while (leftArrayPointer < leftArray.size())
	{
		numbersArray[i] = leftArray[leftArrayPointer];
		i++;
		leftArrayPointer++;
	}

	while (rightArrayPointer < rightArray.size())
	{
		numbersArray[i] = rightArray[rightArrayPointer];
		i++;
		rightArrayPointer++;
	}
}

void mergeSort(std::vector<int> &numbersArray, int leftLimit, int rightLimit)
{
	if (rightLimit - leftLimit  <= 0)
	{
		return;
	}

	int arrayLength = rightLimit - leftLimit;
	int middlePoint = leftLimit + (arrayLength / 2);

	mergeSort(numbersArray, leftLimit, middlePoint);
	mergeSort(numbersArray, middlePoint + 1, rightLimit);

	//mergeArraysAscending(numbersArray, leftLimit, middlePoint, rightLimit);
	mergeArraysDescending(numbersArray, leftLimit, middlePoint, rightLimit);
}

int main()
{
	//std::vector<int> unsortedArray = { 2, 8, 5, 3, 9, 4, 2 };
	std::vector<int> unsortedArray = { 2, 8, 15, 3, 9, 4, 2, 14, 13, 1, 7, 5, 6, 20 };

	mergeSort(unsortedArray, 0, unsortedArray.size() - 1);
	printArray(unsortedArray);

	return 0;
}