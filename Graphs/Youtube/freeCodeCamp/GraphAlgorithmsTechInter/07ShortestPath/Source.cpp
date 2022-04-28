#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <utility>

// Global Variables
std::set<char> visitedNodes;

enum PATHSIZES
{
	PS_BEGGINING = 0,
	PS_NOPATH = -1
};

enum VALUES
{
	V_EMPTY = 0,
	V_EXPLOREDNODE = -1
};

struct Graph
{
	void convertEdgeListToAdjacencyList(std::vector<std::vector<char>>& edgeList)
	{
		for (std::vector<char> edge : edgeList)
		{
			mAdjacencyList[edge[0]].push_back(edge[1]);
			mAdjacencyList[edge[1]].push_back(edge[0]);
		}
	}

	void printAdjacencyList(char node)
	{
		for (char neighbor : mAdjacencyList[node])
		{
			std::cout << "Elemento: " << neighbor << std::endl;
		}
	}

	std::unordered_map<char, std::vector<char>> mAdjacencyList;
};

// IMPORTANT TO NOTICE: In this particular problem, the breadht traversal has linear complexity, and
// because of how it expands, the moment it finds the destination, it can be assumed that the path that
// found it is the shortest one (see video explanation if it is not clear why).
// Depth search it is very likely that is going to expend more time exploring, and once you find the destination,
// you are going to have to compare if it is the shortest path indeed.
// Besides, I investigated how to implement DFS in this scenario and tbh is very complicated, is not worth it, I even saw a joke saying that a good
// way to tweek DFS algorithm to make it work in this problem, is to change the stack for a queue (osea el chiste es
// que nmms uses BFS y te dejes de jaladas con DFS jajaja)
// NOTE: Breadth first performs better where it comes to find the nearest neighbor or the shortest path. Depth
// first performs better when it comes to solving a puzzle or topological solving.

int shortestPathBFS(Graph& graph, char start, char destiny)
{
	std::queue<std::pair<char, int>> queue;
	queue.push({ start, PS_BEGGINING });


	while (queue.size() > V_EMPTY)
	{
		std::pair<char, int> currentNodePair = queue.front();
		char currentNode = currentNodePair.first;
		int currentPathSize = currentNodePair.second;

		queue.pop();

		if (currentNode == destiny)
		{
			return currentPathSize;
		}

		if (visitedNodes.find(currentNode) != visitedNodes.end())
		{
			continue;
		}

		visitedNodes.insert(currentNode);

		for (char neighbor : graph.mAdjacencyList[currentNode])
		{
			queue.push({ neighbor, currentPathSize + 1 });
		}

	}

	return PS_NOPATH;
}

int main()
{
	std::vector<std::vector<char>> edges =
	{
		{'w', 'x'},
		{'x', 'y'},
		{'z', 'y'},
		{'z', 'v'},
		{'w', 'v'}
	};

	Graph graph = Graph();
	graph.convertEdgeListToAdjacencyList(edges);

	int shortestPath = shortestPathBFS(graph, 'x', 'z');

	if (shortestPath > 0)
	{
		std::cout << "The shortestPath is: " << shortestPath << std::endl;
	}
	else
	{
		std::cout << "There is no path to the established destiny." << std::endl;
	}

	return 0;
}