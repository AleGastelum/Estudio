#include <iostream>
#include <string>
#include <stack>
#include <vector>

class Node
{
public:
	Node(std::string val) :
		mVal(val),
		mLeft(nullptr),
		mRight(nullptr)
	{
	}

	std::string mVal;
	Node* mLeft;
	Node* mRight;
};

void printVector(std::vector<std::string>& vector)
{
	for (auto value : vector)
	{
		std::cout << "Value: " << value << std::endl;
	}
}

std::vector<std::string> depthFirstValuesIterative(Node* root)
{
	std::vector<std::string> results;

	if (root == nullptr)
	{
		return results;
	}

	std::stack<Node*> stack;
	stack.push(root);

	while (stack.size() > 0)
	{
		Node* currentNode = stack.top();
		stack.pop();

		results.push_back(currentNode->mVal);

		std::cout << "Current: " << currentNode->mVal << std::endl;

		if (currentNode->mRight != nullptr)
		{
			stack.push(currentNode->mRight);
		}

		if (currentNode->mLeft != nullptr)
		{
			stack.push(currentNode->mLeft);
		}
	}

	return results;
}

std::vector<std::string> depthFirstValuesRecursive(Node* root)
{
	if (root == nullptr)
	{
		return {};
	}

	std::vector<std::string> leftValues = depthFirstValuesRecursive(root->mLeft);
	std::vector<std::string> rightValues = depthFirstValuesRecursive(root->mRight);

	std::vector<std::string> results;

	results.push_back(root->mVal);

	for (auto leftValue : leftValues)
	{
		results.push_back(leftValue);
	}

	for (auto rightValue : rightValues)
	{
		results.push_back(rightValue);
	}

	return results;
}

int main()
{
	Node* a = new Node("a");
	Node* b = new Node("b");
	Node* c = new Node("c");
	Node* d = new Node("d");
	Node* e = new Node("e");
	Node* f = new Node("f");

	a->mLeft = b;
	a->mRight = c;

	b->mLeft = d;
	b->mRight = e;

	c->mRight = f;

	std::cout << std::endl;
	//std::vector<std::string> results = depthFirstValuesIterative(a);
	std::vector<std::string> results = depthFirstValuesRecursive(a);

	printVector(results);

	return 0;
}