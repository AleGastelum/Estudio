#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>

// Global variables
std::set<char> visited;

struct Graph
{
	std::unordered_map<char, std::vector<char>> AdjacencyList;

	void createAdjacencyList(std::vector<std::vector<char>>& edges)
	{
		for (std::vector<char> edge : edges)
		{
			AdjacencyList[edge[0]].push_back(edge[1]);
			AdjacencyList[edge[1]].push_back(edge[0]);
		}
	}

	void printAdjacencyListNodeConnections(char node)
	{
		for (char node : AdjacencyList[node])
		{
			std::cout << "Elemento: " << node << std::endl;
		}
	}
};

bool hasPathDepthFirstRecursive(Graph& graph, char source, char destination)
{
	if (source == destination)
	{
		return true;
	}

	if (visited.find(source) != visited.end())
	{
		return false;
	}

	visited.insert(source);

	for (char neighbor : graph.AdjacencyList[source])
	{
		if (hasPathDepthFirstRecursive(graph, neighbor, destination))
		{
			return true;
		}
	}

	return false;
}

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

		if (visited.find(currentSource) != visited.end())
		{
			continue;
		}

		visited.insert(currentSource);

		for (auto neighbor : graph.AdjacencyList[currentSource])
		{
			stack.push(neighbor);
		}
	}

	return false;
}

bool hasPathBreadthFirstIterative(Graph& graph, char source, char destination)
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

		if (visited.find(currentSource) != visited.end())
		{
			continue;
		}

		visited.insert(currentSource);

		for (auto neighbor : graph.AdjacencyList[currentSource])
		{
			queue.push(neighbor);
		}
	}

	return false;
}

int main()
{
	std::vector<std::vector<char>> edges =
	{
		{'i', 'j'},
		{'k', 'i'},
		{'m', 'k'},
		{'k', 'l'},
		{'o', 'n'}
	};

	Graph graph = Graph();
	graph.createAdjacencyList(edges);

	// bool hasPath = hasPathDepthFirstRecursive(graph, 'n', 'j');
	// bool hasPath = hasPathDepthFirstIterative(graph, 'o', 'm');
	bool hasPath = hasPathBreadthFirstIterative(graph, 'k', 'o');
	
	if (hasPath)
	{
		std::cout << "There is a path" << std::endl;
	}
	else
	{
		std::cout << "There is not a path" << std::endl;
	}

	return 0;
}