#include <iostream>
#include <vector>

// Main functions
long long gridTraveler(int m, int n);
std::vector<std::vector<long long>>& instantiateGrid(std::vector<std::vector<long long>>& grid2, int m, int n);

int main()
{
	long long result;

	//result = gridTraveler(1, 1); // 1
	//result = gridTraveler(2, 3); // 3
	//result = gridTraveler(3, 2); // 3
	//result = gridTraveler(3, 3); // 6
	result = gridTraveler(18, 18); // 2333606220

	std::cout << "Result: " << result << std::endl;

	return 0;
}

long long gridTraveler(int m, int n)
{
	std::vector<std::vector<long long>> grid;
	instantiateGrid(grid, m, n);

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j + 1 <= n)
			{
				grid[i][j + 1] += grid[i][j];
			}

			if (i + 1 <= m)
			{
				grid[i + 1][j] += grid[i][j];
			}
		}
	}

	return grid[m][n];
}

std::vector<std::vector<long long>>& instantiateGrid(std::vector<std::vector<long long>>& rows, int m, int n)
{
	for (int i = 0; i <= m; i++)
	{
		std::vector<long long> columns(n + 1, 0);
		rows.push_back(columns);
	}

	rows[1][1] = 1;

	return rows;
}