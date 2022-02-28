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

std::vector<int> bubbleSort(std::vector<int> numsArray)
{
	for (int i = 1; i < numsArray.size(); i++)
	{
		for (int j = 0; j < numsArray.size() - 1 - i; j++)
		{
			if (numsArray[j] > numsArray[j + 1])
			{
				swap(numsArray[j], numsArray[j + 1]);
			}
		}
	}

	return numsArray;
}

int main()
{
	std::vector<int> unsortedArray = { 2, 8, 5, 3, 9, 4, 1 };
	std::vector<int> sortedArray = bubbleSort(unsortedArray);

	printArray(unsortedArray);
	printArray(sortedArray);
}