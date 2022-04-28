#include<iostream>
#include<stack>
#include<queue>

// Nota: En este problema, los puntos visitados los puedes almacenar en alguna
// estructura de datos como se ha hecho en los problemas pasados. Sin embargo,
// aquí se aplicará otra alternativa vista en samsung, que es simplemente 
// modificar el valor de los nodos visitados a "agua", basicamente eliminarlos.
// Como cuando se haga contacto con algún nodo de una isla todos sus nodos serán 
// visitados mediante DFS o BFS, pues no habrá necesidad de volver a analizar dicha isla,
// por lo que sus nodos pueden "eliminarse" sin problema alguno para representar que ya
// fueron visitados.

char grid[6][5] = {
		{'w', 'l', 'w', 'w', 'w'},
		{'w', 'l', 'w', 'w', 'w'},
		{'w', 'w', 'w', 'l', 'w'},
		{'w', 'w', 'l', 'l', 'w'},
		{'l', 'w', 'w', 'l', 'l'},
		{'l', 'l', 'w', 'w', 'w'}
};

//char grid[6][6] = {
//	{'w', 'l', 'w', 'w', 'l', 'w'},
//	{'l', 'l', 'w', 'w', 'l', 'w'},
//	{'w', 'l', 'w', 'w', 'w', 'l'},
//	{'w', 'w', 'w', 'l', 'l', 'w'},
//	{'w', 'l', 'w', 'l', 'l', 'w'},
//	{'w', 'w', 'w', 'w', 'w', 'w'}
//};

struct Coordinates
{
	Coordinates(int x, int y)
		: mX(x),
		mY(y)
	{}

	void setCoordinates(int x, int y)
	{
		mX = x;
		mY = y;
	}

	int mX;
	int mY;
};

enum DIRECTIONS
{
	D_LEFT,
	D_UP,
	D_RIGHT,
	D_DOWN,
	D_DIRECTIONS
};

enum MAPLIMITS
{
	MP_X_LIMIT = 5,
	MP_Y_LIMIT = 6
};

const Coordinates directions[D_DIRECTIONS] = {
	Coordinates(-1, 0),
	Coordinates(0, 1),
	Coordinates(1, 0),
	Coordinates(0, -1)
};

void iterateGrid();
void traverseIslandDFSR(Coordinates currentCoordinate);
void traverseIslandDFSI(Coordinates currentCoordinate);
void traverseIslandBFS(Coordinates currentCoordinate);
bool isInBounds(Coordinates coordinate);
bool isLand(Coordinates coordinate);

int landCount = 0;

int main()
{
	iterateGrid();

	return 0;
}

void iterateGrid()
{
	Coordinates currentCoordinate(0, 0);

	for (int row = 0; row < MP_Y_LIMIT; row++)
	{
		for (int col = 0; col < MP_X_LIMIT; col++)
		{
			currentCoordinate.setCoordinates(col, row);
			if (isLand(currentCoordinate))
			{
				//std::cout << "(" << currentCoordinate.mX << ", " << currentCoordinate.mY << "), ";
				landCount++;
				traverseIslandDFSR(currentCoordinate);
			}
		}

		//std::cout << std::endl;
	}

	std::cout << "Land Count: " << landCount << std::endl;
}

bool isInBounds(Coordinates coordinate)
{
	if (coordinate.mX >= 0 && coordinate.mX < MP_X_LIMIT && coordinate.mY >= 0 && coordinate.mY < MP_Y_LIMIT)
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

void traverseIslandDFSR(Coordinates currentCoordinate)
{
	grid[currentCoordinate.mY][currentCoordinate.mX] = 'w';

	Coordinates newCoordinate(0, 0);

	for (int direction = D_LEFT; direction < D_DIRECTIONS; direction++)
	{
		newCoordinate.setCoordinates(
			currentCoordinate.mX + directions[direction].mX,
			currentCoordinate.mY + directions[direction].mY
		);

		if (isInBounds(newCoordinate) && isLand(newCoordinate))
		{
			traverseIslandDFSR(newCoordinate);
		}
	}
}

void traverseIslandDFSI(Coordinates currentCoordinate)
{
	std::stack<Coordinates> stack;
	Coordinates newCoordinate(0, 0);

	stack.push(currentCoordinate);


	while (stack.size() > 0)
	{
		currentCoordinate.setCoordinates(stack.top().mX, stack.top().mY);
		stack.pop();

		grid[currentCoordinate.mY][currentCoordinate.mX] = 'w';

		for (int direction = D_LEFT; direction < D_DIRECTIONS; direction++)
		{
			newCoordinate.setCoordinates(
				currentCoordinate.mX + directions[direction].mX,
				currentCoordinate.mY + directions[direction].mY
				);

			if (isInBounds(newCoordinate) && isLand(newCoordinate))
			{
				stack.push(newCoordinate);
			}
		}
	}
}

void traverseIslandBFS(Coordinates currentCoordinate)
{
	std::queue<Coordinates> queue;
	Coordinates newCoordinate(0, 0);

	queue.push(currentCoordinate);

	while (queue.size() > 0)
	{
		currentCoordinate.setCoordinates(queue.front().mX, queue.front().mY);
		queue.pop();

		grid[currentCoordinate.mY][currentCoordinate.mX] = 'w';

		for (int direction = D_LEFT; direction < D_DIRECTIONS; direction++)
		{
			newCoordinate.setCoordinates(
				currentCoordinate.mX + directions[direction].mX,
				currentCoordinate.mY + directions[direction].mY
			);

			if (isInBounds(newCoordinate) && isLand(newCoordinate))
			{
				queue.push(newCoordinate);
			}
		}
	}
}