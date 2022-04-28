#include <iostream>
#include <vector>

// Main functions
long long fibTabulation(int fibPosition);

int main()
{
	//long long result = fibTabulation(6);
	//long long result = fibTabulation(7);
	//long long result = fibTabulation(8);
	long long result = fibTabulation(50);

	std::cout << "Result: " << result << std::endl;

	return 0;
}

long long fibTabulation(int fibPosition)
{
	// Tabulation section
	std::vector<long long> tabulationTable(fibPosition + 1, 0);

	// Fibonacci section
	tabulationTable[1] = 1;

	for (int i = 1; i < fibPosition; i++)
	{
		tabulationTable[i + 1] += tabulationTable[i];

		if ((i + 2) <= fibPosition)
		{
			tabulationTable[i + 2] += tabulationTable[i];
		}
	}

	return tabulationTable[fibPosition];
}