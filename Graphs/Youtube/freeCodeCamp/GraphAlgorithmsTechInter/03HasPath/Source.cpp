#include <iostream>
#include <unordered_map>;
#include <vector>
#include <stack>
#include <queue>

struct Graph
{
	Graph(std::unordered_map<char, std::vector<char>> adjacencyList)
		: AdjacencyList(adjacencyList)
	{}

	std::unordered_map<char, std::vector<char>> AdjacencyList;
};

bool hasPathDepthFirstIterative(Graph& graph, char source, char destination)
{
	std::stack<char> stack;
	stack.push(source);

	while (stack.size() > 0)
	{
		char currentSource = stack.top();
		stack.pop();

		if (currentSource == destination)
		{
			return true;
		}

		for (char neighbor : graph.AdjacencyList[currentSource])
		{
			stack.push(neighbor);
		}
	}

	return false;
}

bool hasPathDepthFirstRecursive(Graph& graph, char source, char destination)
{
	if (source == destination)
	{
		return true;
	}

	for (char neighbor : graph.AdjacencyList[source])
	{
		if (hasPathDepthFirstRecursive(graph, neighbor, destination))
		{
			return true;
		}
	}

	return false;
}

bool hasPathBreadthFirst(Graph& graph, char source, char destination)
{
	std::queue<char> queue;
	queue.push(source);

	while (queue.size() > 0)
	{
		char currentSource = queue.front();
		queue.pop();

		if (currentSource == destination)
		{
			return true;
		}

		for (char neighbor : graph.AdjacencyList[currentSource])
		{
			queue.push(neighbor);
		}
	}

	return false;
}

int main()
{
	std::unordered_map<char, std::vector<char>> adjacencyList =
	{
		{'f', {'g', 'i'}},
		{'g', {'h'}},
		{'h', {}},
		{'i', {'g', 'k'}},
		{'j', {'i'}},
		{'k', {}}
	};

	Graph graph = Graph(adjacencyList);

	// bool hasPath = hasPathDepthFirstIterative(graph, 'f', 'j');
	bool hasPath = hasPathDepthFirstRecursive(graph, 'i', 'h');
	// bool hasPath = hasPathBreadthFirst(graph, 'f', 'h');

	if (hasPath)
	{
		std::cout << "There is a path" << std::endl;
	}
	else
	{
		std::cout << "There is no path" << std::endl;
	}

	return 0;
}