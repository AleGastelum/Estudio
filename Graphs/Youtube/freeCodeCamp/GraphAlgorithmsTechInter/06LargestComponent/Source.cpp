#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <vector>
#include <utility>
#include <set>

//Global Variables
std::set<int> visitedNodes;

struct Graph
{
	Graph(std::unordered_map<int, std::vector<int>> adjacencyList)
		: AdjacencyList(adjacencyList)
	{}

	std::unordered_map<int, std::vector<int>> AdjacencyList;
};

int iterateNodes(Graph& graph);
int depthFirstRecursive(Graph& graph, int source);
int depthFirstIterative(Graph& graph, int source);
int breadthFirstIterative(Graph& graph, int source);

int main()
{
	std::unordered_map<int, std::vector<int>> adjacencyList = {
		{0, {1, 5, 8}},
		{1, {0}},
		{2, {3, 4}},
		{3, {2, 4}},
		{4, {2, 3}},
		{5, {0, 8}},
		{8, {0, 5}}
	};

	Graph graph = Graph(adjacencyList);

	int largestComponent = iterateNodes(graph);

	std::cout << "Largest Component: " << largestComponent << std::endl;

	return 0;
}

int iterateNodes(Graph& graph)
{
	int largestComponent = 0;

	for (std::pair<int, std::vector<int>> node : graph.AdjacencyList)
	{
		int currentComponentSize = breadthFirstIterative(graph, node.first);

		if (currentComponentSize > largestComponent)
		{
			largestComponent = currentComponentSize;
		}
	}

	return largestComponent;
}

int depthFirstRecursive(Graph& graph, int source)
{
	if (visitedNodes.find(source) != visitedNodes.end())
	{
		return 0;
	}

	visitedNodes.insert(source);
	int currentSize = 1;

	for (int neighbor : graph.AdjacencyList[source])
	{
		currentSize += depthFirstRecursive(graph, neighbor);
	}

	return currentSize;
}

int depthFirstIterative(Graph& graph, int source)
{
	if (visitedNodes.find(source) != visitedNodes.end())
	{
		return 0;
	}

	std::stack<int> stack;
	stack.push(source);

	int currentSize = 0;

	while (stack.size() > 0)
	{
		int currentSource = stack.top();
		stack.pop();

		if (visitedNodes.find(currentSource) != visitedNodes.end())
		{
			continue;
		}

		visitedNodes.insert(currentSource);
		currentSize++;

		for (int neighbor : graph.AdjacencyList[currentSource])
		{
			stack.push(neighbor);
		}
	}

	return currentSize;
}

int breadthFirstIterative(Graph& graph, int source)
{
	if (visitedNodes.find(source) != visitedNodes.end())
	{
		return 0;
	}

	std::queue<int> queue;
	queue.push(source);

	int currentSize = 0;

	while (queue.size() > 0)
	{
		int currentSource = queue.front();
		queue.pop();

		if (visitedNodes.find(currentSource) != visitedNodes.end())
		{
			continue;
		}

		visitedNodes.insert(currentSource);
		currentSize++;

		for (int neighbor : graph.AdjacencyList[currentSource])
		{
			queue.push(neighbor);
		}
	}

	return currentSize;
}