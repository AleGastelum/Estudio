#include <iostream>
#include <stack>
#include <queue>

enum DIRECTIONS
{
	D_LEFT,
	D_UP,
	D_RIGHT,
	D_DOWN,
	D_TOTAL_DIRECTIONS
};

enum MAX_VALUES
{
	MV_MAX_DIMENSIONS = 6
};

enum DEFAULTS
{
	D_COUNT_START = 0
};

struct Coordinates
{
	Coordinates()
	{
		mX = 0;
		mY = 0;
	}

	Coordinates(int x, int y)
	{
		mX = x;
		mY = y;
	}

	void setCoordinates(int x, int y)
	{
		mX = x;
		mY = y;
	}

	int mX;
	int mY;
};

// Global Variables
char grid[MV_MAX_DIMENSIONS][MV_MAX_DIMENSIONS] = {
	{'w', 'l', 'w', 'w', 'l', 'w'},
	{'l', 'l', 'w', 'w', 'l', 'w'},
	{'w', 'l', 'w', 'w', 'w', 'w'},
	{'w', 'w', 'w', 'l', 'l', 'w'},
	{'w', 'w', 'w', 'l', 'l', 'w'},
	{'w', 'w', 'w', 'l', 'w', 'w'},
};

//char grid[MV_MAX_DIMENSIONS][MV_MAX_DIMENSIONS] = {
//	{'w', 'l', 'w', 'w', 'w', 'w'},
//	{'w', 'l', 'w', 'w', 'w', 'w'},
//	{'w', 'w', 'w', 'l', 'w', 'w'},
//	{'w', 'w', 'l', 'l', 'w', 'w'},
//	{'l', 'w', 'w', 'l', 'l', 'w'},
//	{'l', 'l', 'w', 'w', 'w', 'w'},
//};

Coordinates directions[D_TOTAL_DIRECTIONS]
{
	Coordinates(-1, 0),
	Coordinates(0, -1),
	Coordinates(1, 0),
	Coordinates(0, 1)
};

unsigned int minIsland = 1 << 31;

// Grid Iteration function
void iterateGrid();

// Traversing functions
int traverseIslandDFSR(Coordinates currentCoordinate, int islandCount);
int traverseIslandDFSI(Coordinates currentCoordinate, int islandCount);
int traverseIslandBFS(Coordinates currentCoordinate, int islandCount);

// Auxiliar functions
bool inBounds(Coordinates coordinate);
bool isLand(Coordinates coordinate);
void removeLandSpace(Coordinates coordinate);

int main()
{
	iterateGrid();

	return 0;
}

void iterateGrid()
{
	for (int row = 0; row < MV_MAX_DIMENSIONS; row++)
	{
		for (int col = 0; col < MV_MAX_DIMENSIONS; col++)
		{
			if (isLand(Coordinates(col, row)))
			{
				int islandCount = traverseIslandDFSI(Coordinates(col, row), D_COUNT_START);
				std::cout << "Conteo: " << islandCount << std::endl;
				
				minIsland = (islandCount < minIsland) ? islandCount : minIsland;
			}
			// std::cout << grid[row][col] << ", ";
		}

		// std::cout << std::endl;
	}

		std::cout << "Menor Isla: " << minIsland << std::endl;
}

int traverseIslandDFSR(Coordinates currentCoordinate, int islandCount)
{
	Coordinates newCoordinate;
	removeLandSpace(currentCoordinate);
	islandCount++;

	for (int direction = D_LEFT; direction < D_TOTAL_DIRECTIONS; direction++)
	{
		newCoordinate.setCoordinates(
			currentCoordinate.mX + directions[direction].mX,
			currentCoordinate.mY + directions[direction].mY
		);

		if (inBounds(newCoordinate) && isLand(newCoordinate))
		{
			islandCount += traverseIslandDFSR(newCoordinate, D_COUNT_START);
		}
	}

	return islandCount;
}

// Corregirlo, una de las islas las cuenta mal
int traverseIslandDFSI(Coordinates currentCoordinate, int islandCount)
{
	std::stack<Coordinates> stack;
	Coordinates newCoordinate;

	stack.push(currentCoordinate);

	while (stack.size() > 0)
	{
		currentCoordinate = stack.top();
		stack.pop();
		islandCount++;

		removeLandSpace(currentCoordinate);

		for (int direction = D_LEFT; direction < D_TOTAL_DIRECTIONS; direction++)
		{
			newCoordinate.setCoordinates(
				currentCoordinate.mX + directions[direction].mX,
				currentCoordinate.mY + directions[direction].mY
			);

			if (inBounds(newCoordinate) && isLand(newCoordinate))
			{
				stack.push(newCoordinate);
			}
		}
	}

	return islandCount;
}

bool inBounds(Coordinates coordinate)
{
	if (coordinate.mX >= 0 && coordinate.mX < MV_MAX_DIMENSIONS && coordinate.mY >= 0 && coordinate.mY < MV_MAX_DIMENSIONS)
	{
		return true;
	}

	return false;
}

bool isLand(Coordinates coordinate)
{
	if (grid[coordinate.mY][coordinate.mX] == 'l')
	{
		return true;
	}

	return false;
}

void removeLandSpace(Coordinates coordinate)
{
	grid[coordinate.mY][coordinate.mX] = 'w';
}