#include <iostream>
#include <utility>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
#include <vector>

// Global Variables
std::set<int> visitedNodes;

struct Graph
{
	Graph(std::unordered_map<int, std::vector<int>> adjacencyList)
		: AdjacencyList(adjacencyList)
	{}

	std::unordered_map<int, std::vector<int>> AdjacencyList;
};

int iterateNodes(Graph& graph);
bool depthFirstRecursive(Graph& graph, int source);
bool depthFirstIterative(Graph& graph, int source);
bool breadthFirstIterative(Graph& graph, int source);

int main()
{
	std::unordered_map<int, std::vector<int>> adjacencyList = {
		{1, {2}},
		{2, {1}},
		{3, {}},
		{4, {6}},
		{5, {6}},
		{6, {4, 5, 7, 8}},
		{7, {6}},
		{8, {6}}
	};

	//std::unordered_map<int, std::vector<int>> adjacencyList = {
	//	{0, {8, 1, 5}},
	//	{1, {0}},
	//	{5, {0, 8}},
	//	{8, {0, 5}},
	//	{2, {3, 4}},
	//	{3, {2, 4}},
	//	{4, {3, 2}}
	//};

	Graph graph = Graph(adjacencyList);

	int connectedComponentsCount = iterateNodes(graph);

	std::cout << connectedComponentsCount << std::endl;

	return 0;
}

int iterateNodes(Graph& graph)
{
	int connectedComponentsCount = 0;

	for (std::pair<int, std::vector<int>> node : graph.AdjacencyList)
	{
		//std::cout << node.first << std::endl;
		if (breadthFirstIterative(graph, node.first))
		{
			connectedComponentsCount++;
		}
	}

	return connectedComponentsCount;
}

bool depthFirstRecursive(Graph& graph, int source)
{
	if (visitedNodes.find(source) != visitedNodes.end())
	{
		return false;
	}

	visitedNodes.insert(source);

	for (int neighbor : graph.AdjacencyList[source])
	{
		depthFirstRecursive(graph, neighbor);
	}

	return true;
}

bool depthFirstIterative(Graph& graph, int source)
{
	if (visitedNodes.find(source) != visitedNodes.end())
	{
		return false;
	}

	std::stack<int> stack;
	stack.push(source);

	while (stack.size() > 0)
	{
		int currentSource = stack.top();
		stack.pop();

		if (visitedNodes.find(currentSource) != visitedNodes.end())
		{
			continue;
		}

		visitedNodes.insert(currentSource);

		for (auto neighbor : graph.AdjacencyList[currentSource])
		{
			stack.push(neighbor);
		}
	}

	return true;
}

bool breadthFirstIterative(Graph& graph, int source)
{
	if (visitedNodes.find(source) != visitedNodes.end())
	{
		return false;
	}

	std::queue<int> queue;
	queue.push(source);

	while (queue.size() > 0)
	{
		int currentSource = queue.front();
		queue.pop();

		if (visitedNodes.find(currentSource) != visitedNodes.end())
		{
			continue;
		}

		visitedNodes.insert(currentSource);

		for (int neighbor : graph.AdjacencyList[currentSource])
		{
			queue.push(neighbor);
		}
	}

	return true;
}