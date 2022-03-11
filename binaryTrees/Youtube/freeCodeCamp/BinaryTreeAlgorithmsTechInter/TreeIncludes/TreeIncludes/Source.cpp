#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

class Node {
public:
	Node(std::string val)
		: mVal(val), 
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
	for (auto element : vector)
	{
		std::cout << "Element: " << element << std::endl;
	}
}

bool treeIncludesBreadFirst(Node* root, std::string val)
{
	if (root == nullptr)
	{
		return false;
	}

	std::vector<std::string> results;
	std::queue<Node*> queue;
	queue.push(root);

	while (queue.size() > 0)
	{
		Node* currentNode = queue.front();

		if (currentNode->mVal == val)
		{
			return true;
		}

		queue.pop();

		results.push_back(currentNode->mVal);

		if (currentNode->mLeft != nullptr)
		{
			queue.push(currentNode->mLeft);
		}

		if (currentNode->mRight != nullptr)
		{
			queue.push(currentNode->mRight);
		}
	}

	return false;
}

bool treeIncludesDepthFirstRecursive(Node* root, std::string val)
{
	if (root == nullptr)
	{
		return false;
	}

	if (root->mVal == val)
	{
		return true;
	}

	return treeIncludesDepthFirstRecursive(root->mLeft, val) || treeIncludesDepthFirstRecursive(root->mRight, val);
}

bool treeIncludesDepthFirstIterative(Node* root, std::string val)
{
	if (root == nullptr)
	{
		return false;
	}

	std::vector<std::string> results;
	std::stack<Node*> stack;
	stack.push(root);

	while (stack.size() > 0)
	{
		Node* currentNode = stack.top();
		stack.pop();

		if (currentNode->mVal == val)
		{
			return true;
		}

		if (currentNode->mRight != nullptr)
		{
			stack.push(currentNode->mRight);
		}

		if (currentNode->mLeft != nullptr)
		{
			stack.push(currentNode->mLeft);
		}
	}

	return false;
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

	// bool found = treeIncludesBreadFirst(a, "e");
	//bool found = treeIncludesDepthFirstRecursive(a, "f");
	bool found = treeIncludesDepthFirstIterative(a, "e");

	if (found)
	{
		std::cout << "Elemento encontrado" << std::endl;
	}
	else
	{
		std::cout << "Elemento no encontrado" << std::endl;
	}

	

	return 0;
}