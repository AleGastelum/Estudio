#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <limits>

class Node
{
public:
	Node(int value)
		: mValue(value),
		mLeft(nullptr),
		mRight(nullptr)
	{

	}

	int mValue;
	Node* mLeft;
	Node* mRight;
};

void printVector(std::vector<int>& vector)
{
	for (auto element : vector)
	{
		std::cout << "Elemento: " << element << std::endl;
	}
}

int depthFirstIterative(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	int minValue = root->mValue;
	std::stack<Node*> stack;
	stack.push(root);

	while (stack.size() > 0)
	{
		Node* currentNode = stack.top();
		stack.pop();

		if (currentNode->mValue < minValue)
		{
			minValue = currentNode->mValue;
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

	return minValue;
}

int depthFirstRecursive(Node* root)
{
	if (root == nullptr)
	{
		return std::numeric_limits<int>::max();
	}

	int minLeft = depthFirstRecursive(root->mLeft);
	int minRight = depthFirstRecursive(root->mRight);

	int currentValue = root->mValue;
	currentValue = (minLeft < currentValue) ? minLeft : currentValue;
	currentValue = (minRight < currentValue) ? minRight : currentValue;

	return currentValue;
}

int breadthFirst(Node* root)
{
	if (root == nullptr)
	{
		return {};
	}

	int minValue = root->mValue;
	std::queue<Node*> queue;
	queue.push(root);

	while (queue.size() > 0)
	{
		Node* currentNode = queue.front();
		queue.pop();
		
		minValue = (currentNode->mValue < minValue) ? currentNode->mValue : minValue;

		if (currentNode->mLeft != nullptr)
		{
			queue.push(currentNode->mLeft);
		}

		if (currentNode->mRight != nullptr)
		{
			queue.push(currentNode->mRight);
		}
	}

	return minValue;
}

int main()
{
	Node* a = new Node(5);
	Node* b = new Node(11);
	Node* c = new Node(3);
	Node* d = new Node(4);
	Node* e = new Node(15);
	Node* f = new Node(12);

	a->mLeft = b;
	a->mRight = c;

	b->mLeft = d;
	b->mRight = e;

	c->mRight = f;

	//int results = depthFirstIterative(d);
	//int results = depthFirstRecursive(a);
	int results = breadthFirst(a);

	std::cout << "Min Value: " << results;

	return 0;
}