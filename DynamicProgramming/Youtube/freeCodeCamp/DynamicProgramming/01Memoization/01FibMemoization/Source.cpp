#include <iostream>
#include <unordered_map>

// Global Variables
std::unordered_map<int, long long> foundValues;

// Main Functions
long long fibonacci(int n);

int main()
{
	std::cout << fibonacci(6) << std::endl;
	foundValues.clear();
	
	std::cout << fibonacci(7) << std::endl;
	foundValues.clear();
	
	std::cout << fibonacci(8) << std::endl;
	foundValues.clear();

	std::cout << fibonacci(50) << std::endl;
	foundValues.clear();

	return 0;
}

// Fibonacci with memoization
long long fibonacci(int n)
{
	if (foundValues.count(n))
	{
		return foundValues[n];
	}

	if (n <= 2)
	{
		return 1;
	}

	foundValues[n] = fibonacci(n - 1) + fibonacci(n - 2);

	return foundValues[n];
}