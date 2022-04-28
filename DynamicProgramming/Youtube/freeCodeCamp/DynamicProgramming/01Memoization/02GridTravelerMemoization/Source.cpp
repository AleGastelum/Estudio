#include <iostream>
#include <unordered_map>
#include <string>

// Global variables
std::unordered_map<std::string, long long> foundRoutes;

// Main functions
long long findRoutesOnGrid(int m, int n);

int main()
{
	std::cout << findRoutesOnGrid(1, 1) << std::endl;
	foundRoutes.clear();

	std::cout << findRoutesOnGrid(2, 3) << std::endl;
	foundRoutes.clear();

	std::cout << findRoutesOnGrid(3, 2) << std::endl;
	foundRoutes.clear();

	std::cout << findRoutesOnGrid(3, 3) << std::endl;
	foundRoutes.clear();

	std::cout << findRoutesOnGrid(18, 18) << std::endl;
	foundRoutes.clear();

	return 0;
}

// Find routes using memoization
long long findRoutesOnGrid(int m, int n)
{
	std::string key = (n < m) ? std::to_string(n) + "," + std::to_string(m) : std::to_string(m) + "," + std::to_string(n);

	if (foundRoutes.count(key))
	{
		return foundRoutes[key];
	}

	if (m == 1 && n == 1)
	{
		return 1;
	}

	if (m == 0 || n == 0)
	{
		return 0;
	}

	foundRoutes[key] = findRoutesOnGrid(m - 1, n) + findRoutesOnGrid(m, n - 1);

	return foundRoutes[key];
}