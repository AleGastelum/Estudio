#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

struct Graph
{
	Graph(std::unordered_map<char, std::vector<char>> adjacencyList)
		: AdjacencyList(adjacencyList)
	{}

	std::unordered_map<char, std::vector<char>> AdjacencyList;
};

void breadthFirstPrint(Graph& graph, char source)
{
	std::queue<char> queue;
	queue.push(source);

	while (queue.size() > 0)
	{
		char currentSource = queue.front();
		queue.pop();

		std::cout << "Current Source: " << currentSource << std::endl;

		for (char neighbor : graph.AdjacencyList[currentSource])
		{
			queue.push(neighbor);
		}
	}
}

int main()
{
	std::unordered_map<char, std::vector<char>> adjacencyList =
	{
		{'a', {'c', 'b'}},
		{'b', {'d'}},
		{'c', {'e'}},
		{'d', {'f'}},
		{'e', {}},
		{'f', {}}
	};

	Graph graph = Graph(adjacencyList);

	breadthFirstPrint(graph, 'a');

	return 0;
}