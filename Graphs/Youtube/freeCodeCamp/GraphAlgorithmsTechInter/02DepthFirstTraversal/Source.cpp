#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>

class Graph
{
public:
	Graph(std::unordered_map<char, std::vector<char>>& adjacencyList)
		: AdjacencyList(adjacencyList)
	{}

	std::unordered_map<char, std::vector<char>> AdjacencyList;
};

void depthFirstTraversalIterativePrint(Graph& graph, char source)
{
	std::stack<char> stack;
	stack.push(source);
	
	while (stack.size() > 0)
	{
		char currentSource = stack.top();
		stack.pop();


		for (auto neighbor : graph.AdjacencyList[currentSource])
		{
			stack.push(neighbor);
		}
	}
}

void depthFirstTraversalRecursivePrint(Graph& graph, char source)
{
	std::cout << "Source: " << source << std::endl;
	
	for (char neighbor : graph.AdjacencyList[source])
	{
		depthFirstTraversalRecursivePrint(graph, neighbor);
	}
}

int main()
{
	std::unordered_map <char, std::vector<char>> adjacencyList =
	{
		{'a', {'b', 'c'}},
		{'b', {'d'}},
		{'c', {'e'}},
		{'d', {'f'}},
		{'e', {}},
		{'f', {}}
	};

	Graph graph = Graph(adjacencyList);

	// depthFirstTraversalIterativePrint(graph, 'a');
	depthFirstTraversalRecursivePrint(graph, 'a');
}